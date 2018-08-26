#pragma once

#include <QWidget>
#include "ui_SysSet.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>


class SysSet : public QWidget
{
	Q_OBJECT

public:
	SysSet(QWidget *parent = Q_NULLPTR);
	~SysSet();

	QSerialPort *mserial;
	void serialSendData_(QByteArray bufferdata);
	QByteArray buffer_;

	unsigned short params_cameraPos, params_cameraSew,params_speedPulLead;



private:
	Ui::SysSet ui;
	QTimer *serial_refresh = new QTimer();
	bool flag = false;
	bool serial_flag = false;
	void setSerial(QString portName, unsigned int baud, short data, short parity, short stop);

signals:

	void serial_GetBits();
	void params_2Config();

private slots:

    void serial_dector();
	void serial_config();
	void serialRevData();

	void params_Config();
};
