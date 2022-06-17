#include "Image.h"

#pragma warning(disable : 4996)
Image::Image(const string src, const int typeProcess) : typeProcess(typeProcess)
{
    this->image = cv::imread(src);
}

void Image::showImage()
{
    Image::intensity();
}

void Image::fontSize(int x, int y) noexcept
{
    CONSOLE_FONT_INFOEX cfi{};
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = x;
    cfi.dwFontSize.Y = y;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Image::grayScale() noexcept
{
    cv::Mat greyImage;
    cv::cvtColor(image, greyImage, cv::COLOR_BGR2GRAY);
    image = greyImage;
}

inline void Image::intensity()
{
    double unit = (256.0 + 1) / 68.0;
    int cn = image.channels();
    string str;
    uint8_t *pixelPtr = (uint8_t *)image.data;
    cv::Scalar_<uint8_t> bgrPixel;
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            int R = pixelPtr[i * image.cols * cn + j * cn + 2];
            int G = pixelPtr[i * image.cols * cn + j * cn + 1];
            int B = pixelPtr[i * image.cols * cn + j * cn + 0];
            int grayScaleValue = static_cast<int>((B * 0.0722) + // B
                                                  (G * 0.7152) + // G
                                                  (R * 0.2126)); // R
            int intensity = static_cast<int>(grayScaleValue / unit);
            str = charPixel(intensity);
            pixel += str;
            printf("\033[%d;2;%d;%d;%dm%c\033[0;00m", typeProcess, R, G, B, str[0]);
        }
        pixel += "\n";
        cout << endl;
    }
}

void Image::resize(int x, int y) noexcept
{
    cv::Mat resizeImage;
    cv::resize(image, resizeImage, cv::Size(x, y));
    image = resizeImage;
}

void Image::Imagefile(string name) noexcept
{
    ofstream file;
    file.open(name);
    if (file.is_open())
        file << pixel;

    file.close();
}

string Image::charPixel(int intensity) noexcept
{
    vector<string> map{"$", "@", "B", "%", "8", "&", "W", "M",  "#", "*", "o", "a", "h",  "k", "b", "d", "p",
                       "q", "w", "m", "Z", "O", "0", "Q", "L",  "C", "J", "U", "Y", "X",  "z", "c", "v", "u",
                       "n", "x", "r", "j", "f", "t", "/", "\\", "|", "(", ")", "1", "{",  "}", "[", "]", "?",
                       "-", "_", "+", "~", "<", ">", "i", "!",  "l", "I", ";", ":", "\"", "^", "`", "'", "."};
    return map[intensity];
}
