#include <jni.h>
#include <string>
#include "ZXingOpenCV.h"

#include "GTIN.h"
#include "ReadBarcode.h"

#include <cctype>
#include <chrono>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace cv;

extern "C" JNIEXPORT jobject

JNICALL
Java_com_example_zxing_1java_MainActivity_BarcodeReader(JNIEnv *env, jobject instance, jlong matAddr)
{
    Mat &img = *(Mat *) matAddr;
    Mat gray;
    int colc = img.cols / 2.0;
    int rowc = img.cols / 2.0;
    int ts = 80;
    auto options = ZXing::ReaderOptions();
    options.setIsPure(true);
    options.setTryRotate(true);
    options.setTryHarder(true);
    options.setTryInvert(true);
    std::string res = "TextView";
    auto rect = img(Range(img.rows / 3, img.rows * 2 / 3), Range(colc - 150, colc + 150));
    cvtColor(rect, gray, COLOR_BGR2GRAY);
    equalizeHist(gray, gray);
    int kernel_size = 3;
    cv::GaussianBlur(gray, gray, cv::Size(kernel_size, kernel_size), 0);
//    threshold(gray, binary, ts, 255, THRESH_BINARY); // ２値化

    auto results = ReadBarcodes(gray);
    for (auto&& result : results) {
        DrawResult(rect, result);
        res = result.text();
    }

    cv::line(img, cv::Point(img.cols / 8, img.rows / 3), cv::Point(img.cols / 4, img.rows / 3), cv::Scalar(0, 255, 0), 1);
    cv::line(img, cv::Point(img.cols * 3 / 4, img.rows / 3), cv::Point(img.cols * 7 / 8, img.rows / 3), cv::Scalar(0, 255, 0), 1);

    cv::line(img, cv::Point(img.cols / 8, img.rows * 2 / 3), cv::Point(img.cols / 4, img.rows * 2 / 3), cv::Scalar(0, 255, 0), 1);
    cv::line(img, cv::Point(img.cols * 3 / 4, img.rows * 2 / 3), cv::Point(img.cols * 7 / 8, img.rows * 2 / 3), cv::Scalar(0, 255, 0), 1);

    cv::line(img, cv::Point(img.cols / 8, img.rows / 3), cv::Point(img.cols / 8, img.rows * 4 / 9), cv::Scalar(0, 255, 0), 1);
    cv::line(img, cv::Point(img.cols * 3 / 4, img.rows / 3), cv::Point(img.cols * 3 / 4, img.rows * 4 / 9), cv::Scalar(0, 255, 0), 1);

    cv::line(img, cv::Point(img.cols / 4, img.rows / 3), cv::Point(img.cols / 4, img.rows * 4 / 9), cv::Scalar(0, 255, 0), 1);
    cv::line(img, cv::Point(img.cols * 7 / 8, img.rows / 3), cv::Point(img.cols * 7 / 8, img.rows * 4 / 9), cv::Scalar(0, 255, 0), 1);
    jclass cls = env->FindClass("com/example/zxing_java/Result");
    jmethodID  constructor = env->GetMethodID(cls, "<init>",
                                              "(Ljava/lang/String;J)V");
    jstring jtext = env->NewStringUTF(res.c_str());
    jlong jMatAddr = reinterpret_cast<jlong>(&img);
    jobject ret = env->NewObject(cls, constructor, jtext, jMatAddr);
    return ret;
}
