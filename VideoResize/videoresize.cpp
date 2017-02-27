#include "videoresize.h"

VideoResize::VideoResize(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	makeConnection();
}

VideoResize::~VideoResize()
{

}

void VideoResize::makeConnection()
{
	connect(ui.bt_src, SIGNAL(clicked()), this, SLOT(browseSrc()));
	connect(ui.bt_start, SIGNAL(clicked()), this, SLOT(resizeVideo()));
}

void VideoResize::browseSrc()
{
	QString srcName= QFileDialog::getOpenFileName(this, "Select Source Folder", 
		"C:/Users/joshlo/Documents/MachineLearning");
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
}

void VideoResize::resizeVideo()
{
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
	cv::Size imgSize = cv::Size(inputVideo.get(CV_CAP_PROP_FRAME_WIDTH),
		inputVideo.get(CV_CAP_PROP_FRAME_HEIGHT));
	// get fps
	double fps = inputVideo.get(CV_CAP_PROP_FPS);

	// set up the video writer
	cv::VideoWriter outputVideo;
	if (!outputVideo.open(dstName, codecInt, fps, imgSize))
	{
		std::cout << "Could not open the output video file for write: " << dstName << std::endl;
		return;
	}

	// resize and save
	cv::Mat src, dst;
	int newWidth,newHeight;


	for (;;)
	{
		inputVideo >> src;
		cv::resize(src, dst, cv::Size());



		outputVideo << dst;
	}

	std::cout << "Finished writing video...\n";
}
