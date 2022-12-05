/*#include <opencv2/opencv.hpp>
#include <iostream>
//形态学操作应用-提取水平线和垂直线
using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("C:/tmp/opencv2sample.JPG");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	char INPUT_WIN[] = "input image";
	char OUTPUT_WIN[] = "result image";
	namedWindow(INPUT_WIN, WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);

	Mat gray_src;
	cvtColor(src, gray_src, cv::COLOR_BGR2GRAY);
	imshow("gray image", gray_src);

	Mat binImg;
	adaptiveThreshold(~gray_src, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("binary image", binImg);

	// 水平结构元素
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	// 垂直结构元素
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	// 矩形结构
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	Mat temp;
	erode(binImg, temp, kernel);
	dilate(temp, dst, kernel);
	// morphologyEx(binImg, dst, CV_MOP_OPEN, vline);
	bitwise_not(dst, dst);
	//blur(dst, dst, Size(3, 3), Point(-1, -1));
	imshow("Final Result", dst);

	waitKey(0);
	return 0;
}*/
/*

#include <opencv2/opencv.hpp>
#include <iostream>
#include "math.h"
//图像金字塔 - 上采集与降采集
using namespace cv;
int main(int agrc, char** argv) {
	Mat src, dst;
	src = imread("C:/tmp/opencv2sample.JPG");
	if (!src.data) {
		printf("could not load image...");
		return -1;
	}

	char INPUT_WIN[] = "input image";
	char OUTPUT_WIN[] = "sample up";
	namedWindow(INPUT_WIN, WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_WIN, WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);

	// 上采样
	pyrUp(src, dst, Size(src.cols * 2, src.rows * 2));
	imshow(OUTPUT_WIN, dst);

	// 降采样
	Mat s_down;
	pyrDown(src, s_down, Size(src.cols / 2, src.rows / 2));
	imshow("sample down", s_down);

	// DOG
	Mat gray_src, g1, g2, dogImg;
	cvtColor(src, gray_src, cv::COLOR_BGR2GRAY);
	GaussianBlur(gray_src, g1, Size(5, 5), 0, 0);
	GaussianBlur(g1, g2, Size(5, 5), 0, 0);
	subtract(g1, g2, dogImg, Mat());

	// 归一化显示:线性提亮的过程使用
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);
	imshow("DOG Image", dogImg);

	waitKey(0);
	return 0;
}

*/