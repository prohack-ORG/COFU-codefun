#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;
void
printMatImgInfo(Mat &img){
    int depth = img.depth();
    int type  = img.type();
    int channels = img.channels();
    if(type == CV_16UC1)
        cout<<"Correct type\n";    
    else
        cout<<"Some other type\n";
}
int
main(){
    //Mat test_img1 = Mat(100, 100, CV_8U, Scalar(100));
    Mat test_img1 = imread("test_image2.tiff", IMREAD_UNCHANGED);
    imwrite("test_img_out.tiff", test_img1);
    namedWindow("input", WINDOW_NORMAL);
    imshow("input", test_img1);
    resizeWindow("input", 500, 500);
    waitKey(0);
    printMatImgInfo(test_img1);
    Mat out_img1 = Mat(test_img1.size(), CV_16UC3);
    cvtColor(test_img1, out_img1, CV_BayerRG2BGR);
    out_img1.convertTo(out_img1, CV_16UC3, 0.00390625);
    printMatImgInfo(out_img1);
    imwrite("rgb_img1.jpg", out_img1);
    cout<<"Done\n";
    return 0;
}
