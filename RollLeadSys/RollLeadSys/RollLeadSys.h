#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RollLeadSys.h"
#include "SysSet.h"
#include <QThread>
#include "cvHandle.h"


#define SLIT_FLAG   'S'
#define SYSTEM_START_FLAG  'Z'
#define SYSTEM_STOP_FLAG  'Y'

#define CAMERAREADY_FLAG   'C'

#define CAMERAREADY_FLAG2  'G'

#define FILTER_DETECTINFO 'F'

#define START_VIBRATION_SYSTEM 'A'
#define STOP_VIBRATION_SYSTEM  'B'

#define TURNTABLE_STEP    'T'

#define START_FILTER_SYSTEM   'D'
#define STOP_FILTER_SYSTEM   'E'

class RollLeadSys : public QMainWindow
{
	Q_OBJECT

public:
	RollLeadSys(QWidget *parent = Q_NULLPTR);

private:

	Ui::RollLeadSysClass ui;
	SysSet set_;
	cvHandle cvhandle_;
	QThread set_thread;
	QThread img_thread;

	QTimer refresh_img;


	void ui_allInit();
	QImage mat2QImage(cv::Mat& mat);
	QPixmap mp;
	QByteArray byte_send;


	typedef enum {
		READY = 0,
		NOTREADY,

	}STATUS;

private slots:

    void set_show();
	void order_Check();
	bool eventFilter(QObject *obj, QEvent *event);
	void closeEvent(QCloseEvent *event);

	void params_Config();
	void refresh_Image();

	void start_rolling_system();
	void start_vibration_system();

	void turntable_step();
	void start_filter_system();
};
