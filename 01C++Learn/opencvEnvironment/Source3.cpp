#include "cv.h"
#include "highgui.h"
int main(int argc, char** argv)
{
    IplImage* pImg; //����IplImageָ�� 
    if ((pImg = cvLoadImage("img.JPG", 1)) != 0)
    {
        cvNamedWindow("Image", 1); //�������� 
        cvShowImage("Image", pImg); //��ʾͼ�� 
        cvWaitKey(0); //�ȴ����� 
        cvDestroyWindow("Image"); //���ٴ��� 
        cvReleaseImage(&pImg); //�ͷ�ͼ��ע��pImgǰ��һ��Ҫ��& 
        return 0;
    }
    return -1;
}