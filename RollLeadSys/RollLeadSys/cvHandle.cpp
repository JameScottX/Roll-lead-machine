#include "cvHandle.h"

cvHandle::cvHandle(QObject *parent)
	: QObject(parent)
{
	refreshImage = new QTimer();
	point_Config();
}

cvHandle::~cvHandle()
{
}

void cvHandle::cameraConfig() {

	refreshImage->stop();

	capture4Pos.set(CV_CAP_PROP_FRAME_WIDTH, IMAGEWID);
	capture4Pos.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGEHEIGHT);
	capture4Sew.set(CV_CAP_PROP_FRAME_WIDTH, IMAGEWID);
	capture4Sew.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGEHEIGHT);

	if (!capture4Pos.isOpened() && !capture4Sew.isOpened()) {

		return;/****************/
	}

	connect(refreshImage, SIGNAL(timeout()), this, SLOT(ImageOut()));
	refreshImage->start(80);

}

cv::Mat cvHandle::getFrame_Pos() {

	cv::Mat imageout;

		capture4Pos >> frame_Pos;

		imageout = frame_Pos;
		return imageout;

}

cv::Mat cvHandle::getFrame_Sew() {

	cv::Mat imageout;

	capture4Sew >> frame_Sew;
		//cv::flip(frame_b, frame_b, 1);  //这里需要进行翻转

		imageout = frame_Sew;
		return imageout;

}


void cvHandle::ImageOut() {

	ImagePosOut = image_Handle4_cicle(getFrame_Pos());
	ImageSewOut = image_Handle4_sew(getFrame_Sew());

}

void cvHandle::point_Config() {

	rectangle_[0].x = 120;
	rectangle_[0].y = 140;

	rectangle_[1].x = rectangle_[0].x + length_;
	rectangle_[1].y = rectangle_[0].y ;

	rectangle_[2].x = rectangle_[1].x;
	rectangle_[2].y = rectangle_[0].y + width_;

	rectangle_[3].x = rectangle_[0].x;
	rectangle_[3].y = rectangle_[2].y;

	rectangle_[4].x = rectangle_[0].x;   //中间的缝左边点
	rectangle_[4].y = rectangle_[0].y + (short)width_ / 2;

	rectangle_[5].x = rectangle_[1].x;    //中间的缝右边点
	rectangle_[5].y = rectangle_[4].y;


	show_.x = 310;
	show_.y = 40;

	rec4circle[0].x = 110;
	rec4circle[0].y = 60;

	rec4circle[1].x = rec4circle[0].x + sidelength_;
	rec4circle[1].y = rec4circle[0].y;

	rec4circle[2].x = rec4circle[1].x;
	rec4circle[2].y = rec4circle[1].y + sidelength_;

	rec4circle[3].x = rec4circle[0].x;
	rec4circle[3].y = rec4circle[2].y;


}

cv::Mat cvHandle::image_Handle4_sew(cv::Mat imageGet) {

	cv::Mat temp1,temp2;
	cv::Mat temp_out;
	detected_flag = false;

	

	unsigned int r_value = rectangle_[4].y;
	unsigned short r_count = 1;
	unsigned short out_value = 0;

	if (use_slit_camera) {
		//先行后列
		cv::blur(imageGet, temp1, cv::Size(3, 3));
		cvtColor(temp1, temp2, CV_BGR2GRAY);
		cv::Canny(temp2, temp2, 80, 100, 3);

		for (unsigned int c = rectangle_[0].y; c < rectangle_[0].y + width_; c++) {

			uchar *pix = temp2.ptr<uchar>(c);

			for (unsigned int r = rectangle_[0].x; r < rectangle_[0].x + length_; r++) {

				if (pix[r] != 0) {

					r_value += c;
					r_count++;
				}
			}

		}

		out_value = (unsigned short)r_value / r_count;

		short temp = out_value - rectangle_[4].y;

		if (r_count>150 && abs(temp) <= threshold_) {      //这里判断都检测到位了
			detected_flag = true;
		}

		level_[0].x = rectangle_[5].x;
		level_[1].x = level_[0].x + 20;

		level_[0].y = out_value;
		level_[1].y = out_value;

		temp_out = cv::Scalar::all(0);
		imageGet.copyTo(temp_out, temp2);


	}
	else {
	
		temp_out = imageGet;

	}

	return temp_out;

}


cv::Mat cvHandle::image_Handle4_cicle(cv::Mat imageGet) {
	cv::Mat temp1, temp2;
	cv::Mat temp_out;
	detected_flag2 = false;

	cv::blur(imageGet, temp1, cv::Size(5, 5));
	cvtColor(temp1, temp2, CV_BGR2GRAY);

	if (use_circle_camera ==true) {
	
	//cv::Canny(temp2, temp2, 50, 200, 3);

	cv::Mat temp3 = temp2(cv::Rect(rec4circle[0].x, rec4circle[0].y, sidelength_, sidelength_));

	std::vector<cv::Vec3f>circle_;
	cv::HoughCircles(temp3, circle_, CV_HOUGH_GRADIENT,1,10,100,17,30,0);


	if (circle_.size()==1) {
		detected_flag2 = true;
	}

	temp_out = cv::Scalar::all(0);
	imageGet.copyTo(temp_out, temp2);


	for (size_t i = 0; i < circle_.size(); i++)
	{
		cv::Point center(cvRound(circle_[i][0])+ rec4circle[0].x, cvRound(circle_[i][1])+ rec4circle[0].y);
		int radius = cvRound(circle_[i][2]);
		//绘制圆心  
		cv::circle(temp_out, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
		//绘制圆轮廓  
		cv::circle(temp_out, center, radius, cv::Scalar(155, 50, 255), 3, 8, 0);
	}

	}else{

		temp_out = cv::Scalar::all(0);
		imageGet.copyTo(temp_out, temp2);

     }
	return temp_out;

}
