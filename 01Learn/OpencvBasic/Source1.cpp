/*#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;
/// <summary>
/// 膨胀与腐蚀
/// </summary>
Mat src, dst;
char OUTPUT_WIN[] = "output image";
int element_size = 3;
int max_size = 21;
void CallBack_Demo(int, void*);
int main(int argc, char** argv) {

	src = imread("C:/tmp/opencv1sample.JPG");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);

	namedWindow(OUTPUT_WIN, WINDOW_AUTOSIZE);
	createTrackbar("Element Size :", OUTPUT_WIN, &element_size, max_size, CallBack_Demo);
	CallBack_Demo(0, 0);

	waitKey(0);
	return 0;
}

void CallBack_Demo(int, void*) {
	int s = element_size * 2 + 1;
	Mat structureElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	dilate(src, dst, structureElement, Point(-1, -1), 1);
	//erode(src, dst, structureElement);
	imshow(OUTPUT_WIN, dst);
	return;
}



#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("C:/tmp/opencv1sample.JPG");
	if (!src.data) {
		printf("could not load image...\n");
	}
	//namedWindow("input image", WINDOW_AUTOSIZE);
	//imshow("input image", src);
	char output_title[] = "morphology demo";
	namedWindow(output_title, WINDOW_AUTOSIZE);

	//结构元素的大小的选取会影响相应的最后获得的结果
	Mat kernel = getStructuringElement(MORPH_RECT, Size(11, 11), Point(-1, -1));

	//开操作:CV_MOP_OPEN	闭操作:CV_MOP_CLOSE		梯度:CV_MOP_GRADIENT	顶帽:CV_MOP_TOPHAT:原图像-开操作图像	黑帽:CV_MOP_BLACKHAT:闭操作与原图像之间的插值图像
	morphologyEx(src, dst, 6, kernel);

	

	imshow(output_title, dst);

	waitKey(0);
	return 0;
}*/


/*enum  	{
  CV_MOP_ERODE =0,
  CV_MOP_DILATE =1,
  CV_MOP_OPEN =2,
  CV_MOP_CLOSE =3,
  CV_MOP_GRADIENT =4,
  CV_MOP_TOPHAT =5,
  CV_MOP_BLACKHAT =6
}*/