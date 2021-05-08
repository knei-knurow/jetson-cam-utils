#include <iostream>
#include <string>
#ifndef _WIN32
#include <unistd.h>
#endif
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

#define CAM_APPSINK (1<<0)
#define CAM_UDPSINK (1<<1)
#define CAM_TIMEOVERLAY (1<<2)
#define CAM_IDOVERLAY (1<<3)

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

    GStCamera(unsigned int id, unsigned int width, unsigned int height, unsigned int framerate, unsigned int flags, string sinkFormat = "BGR", string udpParams="");

    string UDPString(string recvIP, int port);

};

