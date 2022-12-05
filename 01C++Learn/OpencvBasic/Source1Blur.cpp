/*
#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;
//ģ��
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("C:/tmp/opencv1sample.JPG");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	char input_title[] = "input image";
	char output_title[] = "blur image";
	namedWindow(input_title, WINDOW_AUTOSIZE);
	namedWindow(output_title, WINDOW_AUTOSIZE);
	imshow(input_title, src);

	//��ֵģ��
	blur(src, dst, Size(111, 12), Point(-1, -1)); //�����size(15,1)�����൱�ڵ�Ӱ֮�е����Ƭ,ģ��
	imshow(output_title, dst);

	//��˹ģ��
	Mat gblur;
	GaussianBlur(src, gblur, Size(11, 121), 11, 11);
	imshow("gaussian blur", gblur);

	waitKey(0);
	return 0;
}



#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("C:/tmp/opencv1sample.JPG");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);

	//medianBlur(src, dst, 3);//��ֵ�˲� 3*3����
	bilateralFilter(src, dst, 15, 100, 5);//�����ǻ��ڵ�,ֻ��ģ����һ��,���Ҫ��ʹ�ø�˹�˲��Ļ�GaussianBlur���д���Ļ�,���ɸ���ģ��.˫�ߵĻ���Ӻ�һ��
	namedWindow("BiBlur Filter Result", WINDOW_AUTOSIZE);
	imshow("BiBlur Filter Result", dst);

	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("Final Result", resultImg);

	waitKey(0);
	return 0;

}
*/