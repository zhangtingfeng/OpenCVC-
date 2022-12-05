/*#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
//轮廓发现
using namespace std;
using namespace cv;

Mat src, dst;
const char* output_win = "findcontours-demo";
int threshold_value = 100;
int threshold_max = 255;
RNG rng;
void Demo_Contours(int, void*);
int main(int argc, char** argv) {
	src = imread("C:/tmp/opencv1sample.JPG");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input-image", WINDOW_AUTOSIZE);
	namedWindow(output_win, WINDOW_AUTOSIZE);
	imshow("input-image", src);
	cvtColor(src, src, 6);

	const char* trackbar_title = "Threshold Value:";
	//创建一个trackbar的过程,前面已经用了好多了.注意trackbar的使用可以应用到项目之中.
	createTrackbar(trackbar_title, output_win, &threshold_value, threshold_max, Demo_Contours);
	Demo_Contours(0, 0);

	waitKey(0);
	return 0;
}

void Demo_Contours(int, void*) {
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	//最后的一个参数false是代表着之直接使用绝对值的方式进行相应的求解,但是如果要是使用true,代表着使用开根号的方式进行相应的求解,这种方式进行相应的求解的时候,会发生计算量大的问题
	Canny(src, canny_output, threshold_value, threshold_value * 2, 3, false);

	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	imshow(output_win, dst);
}

*/