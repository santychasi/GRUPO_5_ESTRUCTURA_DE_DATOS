#pragma once
#ifndef _IMAGE_
#define _IMAGE_
#include <Windows.h>
#include <cwchar>
#include <fstream>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>
using namespace std;
class Image
{
  private:
    cv::Mat image{0};
    int typeProcess{0};
    string pixel;

  public:
    Image(const string, const int);
    void showImage();
    void fontSize(int, int) noexcept;
    void grayScale() noexcept;
    string charPixel(int) noexcept;
    inline void intensity();
    void resize(int, int) noexcept;
    void Imagefile(string) noexcept;
};
#endif
