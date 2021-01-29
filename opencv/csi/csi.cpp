#include <iostream>
#include <string>
#include <unistd.h>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;


class GStCamera
{
    public:

    unsigned int id;
    unsigned int width;
    unsigned int height;
    unsigned int framerate;
    string srcFmt;
    string sinkFmt;

    string GStString;
    cv::VideoCapture cap;

    GStCamera(unsigned int id, unsigned int width, unsigned int height, unsigned int framerate, std::string sinkFormat = "BGR", std::string srcFormat="NV12")
    {

        this->id = id;
        this->width = width;
        this->height = height;
        this->framerate = framerate;
        this->sinkFmt = sinkFormat;
        this->srcFmt = srcFormat;
        
        stringstream ss;

        ss  << "nvarguscamerasrc sensor-id="
            << id
            << " ! video/x-raw(memory:NVMM), format="
            << srcFormat
            << ", width="
            << width
            << ", height="
            << height
            << " ! nvvidconv ! video/x-raw, width="
            << width
            << ", height="
            << height
            << ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)"
            << sinkFormat
            << " ! videoconvert ! appsink ";
        
        GStString = ss.str();      
        this->cap = cv::VideoCapture(GStString);
	}
};



int main(void)
{

    cv::Mat img;

    GStCamera cam(0, 1920, 1080, 30, "BGR", "NV12");   

    cv::VideoCapture vc = cam.cap;    

    sleep(5);    

    vc >> img;

    cv::imwrite("read.bmp", img);
    vc.release();
    
}   
