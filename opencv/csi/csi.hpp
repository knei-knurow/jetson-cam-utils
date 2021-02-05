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

    unsigned int flags;
    unsigned int id;
    unsigned int width;
    unsigned int height;
    unsigned int framerate;
    string sinkFmt;
    
    string GStString;
    cv::VideoCapture cap;

    GStCamera(unsigned int id, unsigned int width, unsigned int height, unsigned int framerate, unsigned int flags, string sinkFormat, string udpParams); 

};

