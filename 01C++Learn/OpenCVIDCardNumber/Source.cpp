#include <iostream>
#include <opencv2/opencv.hpp>

#define CARD_SIZE Size(640, 400)

using namespace cv;
using namespace std;

/**
* 处理图像
* @param src 身份证原图
*/
void handleImage(Mat& src) {
    Mat src_img = src;
    Mat dst_img;
    //imshow("原图", src_img);
    Mat dst;

    // 图像缩放至 640*400
    resize(src_img, src_img, CARD_SIZE);
    imshow("图像缩放", src_img);

    // 灰度化
    cvtColor(src_img, dst, COLOR_BGR2GRAY);
    //imshow("灰度化", dst);

    // 二值化
    threshold(dst, dst, 100, 255, THRESH_BINARY);
    //imshow("二值化", dst);

    // 膨胀
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(20, 10));
    erode(dst, dst, erodeElement);
    //imshow("膨胀", dst);

    // 轮廓检测
    vector<vector<Point>> contours;
    vector<Rect> rects;

    findContours(dst, contours, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    for (int i = 0; i < contours.size(); i++) {
        Rect rect = boundingRect(contours.at(i));
        rectangle(dst, rect, Scalar(0, 255));
        //imshow("轮廓", dst);
        // 筛选轮廓图片
        if (rect.width > rect.height * 9) {
            rects.push_back(rect);
            rectangle(dst, rect, Scalar(0, 0, 255));
        }
    }

    if (rects.size() == 1) {
        dst_img = src_img(rects.at(0));
    }
    else {
        Rect rectTmp = rects.at(0);
        // 遍历查找Y坐标最大的轮廓
        for (int i = 0; i < rects.size(); ++i) {
            Rect rect = rects.at(i);
            if (rect.tl().y > rectTmp.tl().y) {
                rectTmp = rect;
            }
        }
        rectangle(dst, rectTmp, Scalar(255, 255, 0));
        dst_img = src_img(rectTmp);
    }

    imshow("号码图片", dst_img);
}

int main()
{
    std::cout << "身份证识别\n";
    Mat im = imread("C:/tmp/idcard.jpg");
    handleImage(im);
    waitKey(0);
    return 0;
}
