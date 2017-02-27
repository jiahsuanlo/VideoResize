#ifndef VIDEORESIZE_H
#define VIDEORESIZE_H

#include <QtWidgets/QWidget>
#include "GeneratedFiles\ui_videoresize.h"

#include<opencv2\opencv.hpp>
#include <qfiledialog.h>
#include <qmessagebox.h>

class VideoResize : public QWidget
{
	Q_OBJECT

public:
	VideoResize(QWidget *parent = 0);
	~VideoResize();

	void makeConnection();

private slots:
	void browseSrc();
	void resizeVideo();
	void lockAspectRatio(int);
	void widthChanged(const QString&);
private:
	Ui::VideoResizeClass ui;
	double aspectRatio;
};

#endif // VIDEORESIZE_H
