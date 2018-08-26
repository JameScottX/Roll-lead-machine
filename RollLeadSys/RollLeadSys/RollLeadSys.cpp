#include "RollLeadSys.h"
#include <QMessageBox>


RollLeadSys::RollLeadSys(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui_allInit();

	setAttribute(Qt::WA_DeleteOnClose);
	connect(&set_,SIGNAL(serial_GetBits()),this,SLOT(order_Check())); 
	connect(&set_, SIGNAL(params_2Config()), this, SLOT(params_Config()));
	order_Check();
}



void RollLeadSys::set_show(){

	set_.show();
}

void RollLeadSys::ui_allInit() {

	ui.m_Set->installEventFilter(this);
	ui.m_Info->installEventFilter(this);

	set_.moveToThread(&set_thread);
	set_thread.start();

	cvhandle_.moveToThread(&img_thread);
	img_thread.start();

	ui.lb_Camera2->setScaledContents(true);
	ui.lb_Camera1->setScaledContents(true);

	connect(ui.pB_rolling,SIGNAL(released()),this,SLOT(start_rolling_system()));
	connect(ui.pB_vibration,SIGNAL(released()),this,SLOT(start_vibration_system()));
	connect(ui.pB_Turntable,SIGNAL(released()),this,SLOT(turntable_step()));
	connect(ui.pB_Filter,SIGNAL(released()),this,SLOT(start_filter_system()));

	byte_send.resize(1);

}

void RollLeadSys::order_Check() {

	qDebug() << "1111111111111111";

	if (!set_.buffer_.isEmpty()) {      //‘S’判断是否走完，走完停止计时

		if (set_.buffer_.size() == 1) {

			if (set_.buffer_.at(0) == CAMERAREADY_FLAG) {

				cvhandle_.use_slit_camera = true;                 //此处开始狭缝的视觉检测
				qDebug() << "start detecting ！";
			}
			else if (set_.buffer_.at(0) == CAMERAREADY_FLAG2) {   //此处开始圆的检测
			
				cvhandle_.use_circle_camera = true;
			}
			set_.buffer_.clear();
		}
	}
}


void RollLeadSys::params_Config() {

	int temp1 = set_.params_cameraSew;
	int temp2 = set_.params_cameraPos;

	cvhandle_.capture4Sew.open(temp1);
	cvhandle_.capture4Pos.open(temp2);
	cvhandle_.cameraConfig();


	connect(&refresh_img,SIGNAL(timeout()),this,SLOT(refresh_Image()));
	refresh_img.start(80);

}

void RollLeadSys::refresh_Image() {

	cv::Mat ImageSew,ImagePos;
	ImageSew  = cvhandle_.ImageSewOut;
	ImagePos = cvhandle_.ImagePosOut;

	cv::line(ImageSew, cvhandle_.rectangle_[0], cvhandle_.rectangle_[1], cv::Scalar(0, 255, 0), 1, 8);
	cv::line(ImageSew, cvhandle_.rectangle_[1], cvhandle_.rectangle_[2], cv::Scalar(0, 255, 0), 1, 8);
	cv::line(ImageSew, cvhandle_.rectangle_[2], cvhandle_.rectangle_[3], cv::Scalar(0, 255, 0), 1, 8);
	cv::line(ImageSew, cvhandle_.rectangle_[3], cvhandle_.rectangle_[0], cv::Scalar(0, 255, 0), 1, 8);
	cv::line(ImageSew, cvhandle_.rectangle_[4], cvhandle_.rectangle_[5], cv::Scalar(0, 0, 255), 1, 8);

	cv::line(ImageSew, cvhandle_.level_[0], cvhandle_.level_[1], cv::Scalar(255, 0, 0), 1, 8);

	cv::line(ImagePos, cvhandle_.rec4circle[0], cvhandle_.rec4circle[1], cv::Scalar(0, 0, 255), 1, 8);
	cv::line(ImagePos, cvhandle_.rec4circle[1], cvhandle_.rec4circle[2], cv::Scalar(0, 0, 255), 1, 8);
	cv::line(ImagePos, cvhandle_.rec4circle[2], cvhandle_.rec4circle[3], cv::Scalar(0, 0, 255), 1, 8);
	cv::line(ImagePos, cvhandle_.rec4circle[0], cvhandle_.rec4circle[3], cv::Scalar(0, 0, 255), 1, 8);


	if (cvhandle_.detected_flag) {

		byte_send[0] = SLIT_FLAG;
		set_.serialSendData_(byte_send);
		cvhandle_.use_slit_camera = false;

		cv::circle(ImageSew, cvhandle_.show_,13,cv::Scalar(0, 255, 0),25);
	}

	else {
		cv::circle(ImageSew, cvhandle_.show_, 13, cv::Scalar(0, 0, 255), 25);
	}

	if (cvhandle_.detected_flag2) {

		cvhandle_.use_circle_camera = false;

		byte_send[0] = FILTER_DETECTINFO;
		set_.serialSendData_(byte_send);
		

		cv::circle(ImagePos, cvhandle_.show_, 13, cv::Scalar(0, 255, 0), 25);
	}
	else {

		cv::circle(ImagePos, cvhandle_.show_, 13, cv::Scalar(0, 0, 255), 25);
	}

	QImage temp = mat2QImage(ImageSew);
	mp = mp.fromImage(temp);
	ui.lb_Camera2->setPixmap(mp);
	ui.lb_Camera2->show();

    temp = mat2QImage(ImagePos);
	mp = mp.fromImage(temp);
	ui.lb_Camera1->setPixmap(mp);
	ui.lb_Camera1->show();


}

void RollLeadSys::start_rolling_system() {

	static bool temp_flag = true;

	if (temp_flag) {
		byte_send[0] = SYSTEM_START_FLAG;
		set_.serialSendData_(byte_send);
		ui.pB_rolling->setText(QStringLiteral("关闭"));
		temp_flag = !temp_flag;
	}
	else {
		byte_send[0] = SYSTEM_STOP_FLAG;
		set_.serialSendData_(byte_send);
		ui.pB_rolling->setText(QStringLiteral("启动"));
		temp_flag = !temp_flag;
	}

	cvhandle_.use_slit_camera = false;

}
void RollLeadSys::start_vibration_system() {

	static bool temp_flag = true;

	if (temp_flag) {

		byte_send[0] = START_VIBRATION_SYSTEM;
		set_.serialSendData_(byte_send);
		ui.pB_vibration->setText(QStringLiteral("关闭"));
		temp_flag = !temp_flag;
	}
	else {
		byte_send[0] = STOP_VIBRATION_SYSTEM;
		set_.serialSendData_(byte_send);
		ui.pB_vibration->setText(QStringLiteral("启动"));
		temp_flag = !temp_flag;
	}

}

void RollLeadSys:: turntable_step() {

	byte_send[0] = TURNTABLE_STEP;
	set_.serialSendData_(byte_send);

}


void RollLeadSys::start_filter_system() {

	static bool temp_flag = true;

	if (temp_flag) {

		byte_send[0] = START_FILTER_SYSTEM;
		set_.serialSendData_(byte_send);
		ui.pB_Filter->setText(QStringLiteral("关闭"));
		temp_flag = !temp_flag;
	}
	else {
		byte_send[0] = STOP_FILTER_SYSTEM;
		set_.serialSendData_(byte_send);
		ui.pB_Filter->setText(QStringLiteral("启动"));
		temp_flag = !temp_flag;
	}

}

bool RollLeadSys::eventFilter(QObject *obj, QEvent *event) {
	if (obj == ui.m_Set) {

		if (event->type() == QEvent::MouseButtonRelease) {
			set_show();
			return true;
		}
		else {
			return false;
		}
	}
	else if (obj == ui.m_Info) {
	
		if (event->type() == QEvent::MouseButtonRelease) {
			QMessageBox::information(this, QStringLiteral("铅皮卷裹系统"), QStringLiteral("这是一个上位机自动铅皮卷裹系统 作者：付豪"));
			return true;
		}
		else {
			return false;
		}
	
	
	}
	return QMainWindow::eventFilter(obj, event);
}

void RollLeadSys::closeEvent(QCloseEvent *event) {

	/*QMessageBox::StandardButton button;
	button = QMessageBox::question(this, tr("QUIT"), tr("Are you sure to quit?"), QMessageBox::Yes | QMessageBox::No);
	if (button == QMessageBox::No) {

		event->ignore();
	}
	else if (button == QMessageBox::Yes) {

		event->accept();

	}*/
}

QImage RollLeadSys::mat2QImage(cv::Mat& mat)
{

	// 8-bits unsigned, NO. OF CHANNELS = 1

	if (mat.type() == CV_8UC1)

	{

#if 0

		qDebug() << "CV_8UC1";

#endif

		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);

		// Set the color table (used to translate colour indexes to qRgb values)

		image.setColorCount(256);

		for (int i = 0; i < 256; i++)

		{

			image.setColor(i, qRgb(i, i, i));

		}

		// Copy input Mat

		uchar *pSrc = mat.data;

		for (int row = 0; row < mat.rows; row++)

		{

			uchar *pDest = image.scanLine(row);

			memcpy(pDest, pSrc, mat.cols);

			pSrc += mat.step;

		}

		return image;

	}

	// 8-bits unsigned, NO. OF CHANNELS = 3

	else if (mat.type() == CV_8UC3)

	{

		// Copy input Mat

		const uchar *pSrc = (const uchar*)mat.data;

		// Create QImage with same dimensions as input Mat

		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);

		return image.rgbSwapped();

	}

	else if (mat.type() == CV_8UC4)

	{

#if 0

		qDebug() << "CV_8UC4";

#endif

		// Copy input Mat

		const uchar *pSrc = (const uchar*)mat.data;

		// Create QImage with same dimensions as input Mat

		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);

		return image.copy();

	}

	else

	{

#if 0

		qDebug() << "ERROR: Mat could not be converted to QImage.";

#endif

		QMessageBox::information(

			NULL,

			"Error",

			"Image Format Unknown!",

			QMessageBox::Yes | QMessageBox::No,

			QMessageBox::Yes);

		return QImage();

	}

}
