#ifndef VIDEORESIZE_H
#define VIDEORESIZE_H

#include <QtWidgets/QWidget>
#include "GeneratedFiles\ui_videoresize.h"

#include<opencv2\opencv.hpp>
#include <qfiledialog.h>

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
private:
	Ui::VideoResizeClass ui;
};

#endif // VIDEORESIZE_H
