// 7_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat src = cv::imread("D:\\metal-part-distorted-03.png", 1);

	cv::Mat canny;
	Canny(src, canny, 20, 160);

	std::vector<cv::Vec4i> lines;
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 42, 10, 10);

	std::vector<cv::Vec4i>::iterator it = lines.begin();
	for (; it != lines.end(); ++it) {
		int x1 = (*it)[0], y1 = (*it)[1], x2 = (*it)[2], y2 = (*it)[3];
		cv::Point pt1, pt2;
		pt1.x = x1;
		pt1.y = y1;
		pt2.x = x2;
		pt2.y = y2;
		cv::line(src, pt1, pt2, cv::Scalar(0, 0, 255), 2, CV_AA);
	}

	cv::imshow("canny", canny);
	cv::imshow("src", src);
	waitKey(0);
	return 0;
}

