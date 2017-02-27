#include "videoresize.h"

VideoResize::VideoResize(QWidget *parent)
	: QWidget(parent), aspectRatio(0)
{
	ui.setupUi(this);

	ui.pb_convert->setVisible(false);
	makeConnection();
}

VideoResize::~VideoResize()
{

}

void VideoResize::makeConnection()
{
	connect(ui.bt_src, SIGNAL(clicked()), this, SLOT(browseSrc()));
	connect(ui.bt_start, SIGNAL(clicked()), this, SLOT(resizeVideo()));
	connect(ui.ck_aspect, SIGNAL(stateChanged(int)), this, SLOT(lockAspectRatio(int)));
	connect(ui.ed_width, SIGNAL(textChanged(const QString&)), this, SLOT(widthChanged(const QString&)));
}

void VideoResize::browseSrc()
{
	QString srcName= QFileDialog::getOpenFileName(this, "Select Source Folder", 
		"C:\\Users\\Josh Lo\\Documents\\temp");
	QFileInfo fSrc(srcName);

	QString dstName = QString("%1/%2_Resized.%3").arg(fSrc.absolutePath())
		.arg(fSrc.completeBaseName()).arg(fSrc.suffix());
	
	// show file name text
	ui.ed_src->setText(srcName);
	ui.ed_dst->setText(dstName);

	// get image size
	cv::VideoCapture capSrc(srcName.toStdString());
	cv::Mat src;
	if (!capSrc.isOpened())
	{
		std::cout << "Could not open specified video file...\n";
		return;
	}
	capSrc >> src;  // get the first frame
	int width = src.cols;
	int height = src.rows;
	ui.ed_height->setText(QString("%1").arg(height));
	ui.ed_width->setText(QString("%1").arg(width));	
	aspectRatio = double(width) / height;
}

void VideoResize::resizeVideo()
{
	// show the progress bar
	ui.pb_convert->setVisible(true);
	ui.pb_convert->repaint();
	
	std::string srcName = ui.ed_src->text().toStdString();
	std::string dstName = ui.ed_dst->text().toStdString();
	cv::VideoCapture inputVideo(srcName);

	if (!inputVideo.isOpened())
	{
		std::cout << "Could not open the input video: " << srcName << std::endl;
		return;
	}
	
	// get codec info in int form
	int codecInt = static_cast<int>(inputVideo.get(CV_CAP_PROP_FOURCC));
	// get image size
	int newWidth, newHeight;
	newWidth = ui.ed_width->text().toInt();
	newHeight = ui.ed_height->text().toInt();

	cv::Size imgSize = cv::Size(newWidth, newHeight);
	// get fps
	double fps = inputVideo.get(CV_CAP_PROP_FPS);

	int frameCnt = inputVideo.get(CV_CAP_PROP_FRAME_COUNT);

	// set up the video writer
	cv::VideoWriter outputVideo;
	if (!outputVideo.open(dstName, codecInt, fps, imgSize))
	{
		std::cout << "Could not open the output video file for write: " << dstName << std::endl;
		return;
	}

	// resize and save
	cv::Mat src, dst;
	
	int ct = 0;
	for (;;)
	{
		// update progressbar 
		int progress = static_cast<int>(double(ct) / frameCnt*100.0);
		ui.pb_convert->setValue(progress);

		// resize
		inputVideo >> src;
		if (src.rows == 0)
		{
			break;
		}
		cv::resize(src, dst, imgSize);
		outputVideo << dst;
		ct++;
	}


	// hide the progress bar
	ui.pb_convert->setVisible(false);
	ui.pb_convert->repaint();

	std::cout << "Finished writing video...\n";
	QMessageBox msgBox;
	msgBox.setText("Video has been written successfully");
	msgBox.exec();	

}

void VideoResize::lockAspectRatio(int state)
{
	if (state)
	{
		widthChanged(ui.ed_width->text());
		ui.ed_height->setEnabled(false);
	}
	else
	{
		ui.ed_height->setEnabled(true);
	}
}

void VideoResize::widthChanged(const QString &txt)
{
	if (ui.ck_aspect->isChecked() && aspectRatio != 0)
	{
		int height = static_cast<int>(txt.toDouble()/aspectRatio);
		ui.ed_height->setText(QString("%1").arg(height));
	}
}
