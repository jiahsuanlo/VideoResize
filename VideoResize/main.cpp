#include "videoresize.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoResize w;
	w.show();
	return a.exec();
}
