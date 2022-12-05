/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
//直方图概念
using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("C:/tmp/opencv1sample.JPG");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	char INPUT_T[] = "input image";
	char OUTPUT_T[] = "histogram demo";
	namedWindow(INPUT_T, WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_T, WINDOW_AUTOSIZE);
	imshow(INPUT_T, src);

	// 分通道显示
	vector<Mat> bgr_planes;
	split(src, bgr_planes);
	imshow("single channel demo", bgr_planes[0]);//这里是相应的一个单通道的输出

	// 计算直方图
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);

	// 归一化
	int hist_h = 400;
	int hist_w = 512;
	int bin_w = hist_w / histSize;
	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	// render histogram chart
	for (int i = 1; i < histSize; i++) {
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);

		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);

		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);
	}
	imshow(OUTPUT_T, histImage);

	waitKey(0);
	return 0;
}


#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
//直方图比较
using namespace std;
using namespace cv;

string convertToString(double d);
int main(int argc, char** argv) {
	Mat base, test1, test2;
	Mat hsvbase, hsvtest1, hsvtest2;
	base = imread("C:/tmp/opencv1sample.JPG");
	if (!base.data) {
		printf("could not load image...\n");
		return -1;
	}
	test1 = imread("C:/tmp/opencv1sample.JPG");
	test2 = imread("C:/tmp/opencv2sample.JPG");

	cvtColor(base, hsvbase, 40);
	cvtColor(test1, hsvtest1, 40);
	cvtColor(test2, hsvtest2, 40);

	int h_bins = 50; int s_bins = 60;
	int histSize[] = { h_bins, s_bins };
	// hue varies from 0 to 179, saturation from 0 to 255     
	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };
	const float* ranges[] = { h_ranges, s_ranges };
	// Use the o-th and 1-st channels     
	int channels[] = { 0, 1 };
	MatND hist_base;
	MatND hist_test1;
	MatND hist_test2;

	calcHist(&hsvbase, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
	normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsvtest1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
	normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat());

	calcHist(&hsvtest2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false);
	normalize(hist_test2, hist_test2, 0, 1, NORM_MINMAX, -1, Mat());

	double basebase = compareHist(hist_base, hist_base, 2);
	double basetest1 = compareHist(hist_base, hist_test1, 2);
	double basetest2 = compareHist(hist_base, hist_test2, 2);
	double tes1test2 = compareHist(hist_test1, hist_test2, 2);
	printf("test1 compare with test2 correlation value :%f", tes1test2);

	Mat test12;
	test2.copyTo(test12);
	putText(base, convertToString(basebase), Point(50, 50), 3, 1, Scalar(0, 0, 255), 2, LINE_AA);
	putText(test1, convertToString(basetest1), Point(50, 50), 3, 1, Scalar(0, 0, 255), 2, LINE_AA);
	putText(test2, convertToString(basetest2), Point(50, 50), 3, 1, Scalar(0, 0, 255), 2, LINE_AA);
	putText(test12, convertToString(tes1test2), Point(50, 50), 3, 1, Scalar(0, 0, 255), 2, LINE_AA);

	namedWindow("base", WINDOW_AUTOSIZE);
	namedWindow("test1", WINDOW_AUTOSIZE);
	namedWindow("test2", WINDOW_AUTOSIZE);

	imshow("base", base);
	imshow("test1", test1);
	imshow("test2", test2);
	imshow("test12", test12);

	waitKey(0);
	return 0;
}

string convertToString(double d) {
	ostringstream os;
	if (os << d)
		return os.str();
	return "invalid conversion";
}*/