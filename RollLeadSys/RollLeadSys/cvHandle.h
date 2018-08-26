#include <QObject>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QTimer>
#include <QDebug>

#define IMAGEWID   400
#define IMAGEHEIGHT  400


class cvHandle : public QObject
{
	Q_OBJECT

public:

	cvHandle(QObject *parent = 0);

	~cvHandle();

	cv::VideoCapture capture4Pos;
	cv::VideoCapture capture4Sew;
	QTimer *refreshImage ;

	void cameraConfig();
	cv::Mat ImagePosOut, ImageSewOut;

	cv::Point rectangle_[6];
	cv::Point level_[2];
	cv::Point show_;

	cv::Point rec4circle[4];

	short width_ = 30, length_ = 110;
	short sidelength_ = 120;

	void point_Config();
	cv::Mat image_Handle4_sew(cv::Mat imageGet);
	cv::Mat image_Handle4_cicle(cv::Mat imageGet);

	unsigned char threshold_ = 1;

	bool detected_flag = false;
	bool use_slit_camera = false;

	bool detected_flag2 = false;
	bool use_circle_camera = false;

private:
	cv::Mat frame_Pos, frame_Sew;
	cv::Mat getFrame_Pos();
	cv::Mat getFrame_Sew();

private slots:
    void ImageOut();

};
