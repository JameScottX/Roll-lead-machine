#include "SysSet.h"

SysSet::SysSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(serial_refresh, SIGNAL(timeout()), this, SLOT(serial_dector()));
	serial_refresh->start(2000);
	mserial = new QSerialPort();
	connect(ui.pB_connect,SIGNAL(released()),this,SLOT(serial_config()));
	connect(ui.pB_set,SIGNAL(released()),this,SLOT(params_Config()));

}

SysSet::~SysSet()
{
	delete serial_refresh, mserial;
}

void SysSet::serial_dector() {

	QString serial_portName;
	QString serial_systemLocation;
	QString serial_description;
	QString temp;


	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {

		serial_portName = info.portName();
		serial_systemLocation = info.systemLocation();
		serial_description = info.description();

		QString tempOut = serial_portName + serial_systemLocation + serial_description;

		if (!flag) {

			ui.cB_port->addItem(serial_portName);
			flag = true;
		}
		else {

			for (char i = ui.cB_port->count(); i>1; i--) {

				if (serial_portName != ui.cB_port->itemText(i)) {
					ui.cB_port->addItem(serial_portName);
				}
			}

		}

		ui.tB_Info->setText(temp + tempOut);
		temp = tempOut;
	}
}

void SysSet::serial_config() {

	if (!serial_flag) {

		setSerial(ui.cB_port->currentText(), 115200, 8, 0, 0);
		connect(this->mserial, SIGNAL(readyRead()), this, SLOT(serialRevData()));
		serial_refresh->stop();
		ui.tB_Info->setText("Done!");
		ui.pB_connect->setText(QStringLiteral("¶Ï¿ª"));
		serial_flag = true;

	}
	else {

		disconnect(mserial, SIGNAL(readyRead()), this, SLOT(serialRevData()));
		mserial->clear();
		mserial->close();

		ui.tB_Info->setText("Shut Down!");
		serial_refresh->start();
		ui.pB_connect->setText(QStringLiteral("Á´½Ó"));
		serial_flag = false;
		ui.cB_port->clear();
		flag = false;
	}


}

void SysSet::setSerial(QString portName, unsigned int baud, short data, short parity, short stop) {

	mserial->setPortName(portName);
	mserial->open(QIODevice::ReadWrite);
	mserial->setBaudRate(baud);

	switch (data) {

	case 5:mserial->setDataBits(QSerialPort::Data5); break;
	case 6:mserial->setDataBits(QSerialPort::Data6); break;
	case 7:mserial->setDataBits(QSerialPort::Data7); break;
	case 8:mserial->setDataBits(QSerialPort::Data8); break;
	default:break;

	}


	switch (parity) {
	case 0: mserial->setParity(QSerialPort::NoParity); break;
	default:break;
	}
	switch (stop) {
	case 0:mserial->setStopBits(QSerialPort::OneStop); break;
	case 1:mserial->setStopBits(QSerialPort::TwoStop); break;
	default:break;
	}
	mserial->setFlowControl(QSerialPort::NoFlowControl);



}

void SysSet::serialRevData() {

	QByteArray tmp;
	tmp = mserial->readAll();

	buffer_ += tmp;

	emit serial_GetBits();
}

void SysSet::serialSendData_(QByteArray bufferdata) {

	mserial->write(bufferdata);

}

void SysSet::params_Config() {

	params_cameraSew = ui.sB_cameraSew->value();
	params_cameraPos = ui.sB_cameraPos->value();
	emit params_2Config();
}