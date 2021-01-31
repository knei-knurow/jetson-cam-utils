#include "csi.hpp"
#define CAM_APPSINK (1<<0)
#define CAM_UDP     (1<<1)
#define CAM_RTSP    (1<<2)
#define CAM_TIMEOV  (1<<3)
#define CAM_ID_OV   (1<<4)

using namespace std;

GStCamera::GStCamera(unsigned int id, unsigned int width, unsigned int height, unsigned int framerate, unsigned int flags, string sinkFormat = "BGR", string srcFormat="NV12")
{
    this->flags = flags;
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
