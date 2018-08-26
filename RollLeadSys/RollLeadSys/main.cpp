#include "RollLeadSys.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setQuitOnLastWindowClosed(true);
	RollLeadSys w;
	w.show();
	return a.exec();
}
