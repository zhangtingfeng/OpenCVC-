#include <iostream>
#include <opencv2/opencv.hpp>

#define CARD_SIZE Size(640, 400)

using namespace cv;
using namespace std;

/**
* ����ͼ��
* @param src ���֤ԭͼ
*/
void handleImage(Mat& src) {
    Mat src_img = src;
    Mat dst_img;
    //imshow("ԭͼ", src_img);
    Mat dst;

    // ͼ�������� 640*400
    resize(src_img, src_img, CARD_SIZE);
    imshow("ͼ������", src_img);

    // �ҶȻ�
    cvtColor(src_img, dst, COLOR_BGR2GRAY);
    //imshow("�ҶȻ�", dst);

    // ��ֵ��
    threshold(dst, dst, 100, 255, THRESH_BINARY);
    //imshow("��ֵ��", dst);

    // ����
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(20, 10));
    erode(dst, dst, erodeElement);
    //imshow("����", dst);

    // �������
    vector<vector<Point>> contours;
    vector<Rect> rects;

    findContours(dst, contours, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    for (int i = 0; i < contours.size(); i++) {
        Rect rect = boundingRect(contours.at(i));
        rectangle(dst, rect, Scalar(0, 255));
        //imshow("����", dst);
        // ɸѡ����ͼƬ
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
        // ��������Y������������
        for (int i = 0; i < rects.size(); ++i) {
            Rect rect = rects.at(i);
            if (rect.tl().y > rectTmp.tl().y) {
                rectTmp = rect;
            }
        }
        rectangle(dst, rectTmp, Scalar(255, 255, 0));
        dst_img = src_img(rectTmp);
    }

    imshow("����ͼƬ", dst_img);
}

int main()
{
    std::cout << "���֤ʶ��\n";
    Mat im = imread("C:/tmp/idcard.jpg");
    handleImage(im);
    waitKey(0);
    return 0;
}
