#include "gst_src.hpp"
#define CAM_APPSINK (1<<0)
#define CAM_UDPSINK (1<<1)
#define CAM_TIMEOVERLAY (1<<2)
#define CAM_IDOVERLAY (1<<3)
using namespace std;


string GStCamera::UDPString(string recvIP, int port)
{
    stringstream ss;
    
    ss  << "host="
        << recvIP
        << " port="
        << port;

    return ss.str();

}



GStCamera::GStCamera(unsigned int id, unsigned int width, unsigned int height, unsigned int framerate, unsigned int flags, string sinkFormat = "BGR", string udpParams="")
{
    this->flags = flags;
    this->id = id;
    this->width = width;
    this->height = height;
    this->framerate = framerate;
    this->sinkFmt = sinkFormat;

    stringstream ss;
    stringstream overlays_ss;
        
    if(flags & (CAM_TIMEOVERLAY))
    {
        overlays_ss << " ! timeoverlay " ;
    }
    
    if(flags & (CAM_IDOVERLAY))
    {
        

        overlays_ss << " ! textoverlay text =" 
                    << id
                    << " valigment=top haligment=top font-desc=\"Sans, 72\"";
    }


    string overlays = overlays_ss.str();

    
    if(flags & (CAM_APPSINK | CAM_UDPSINK))
    {
        ss  <<  "nvarguscamerasrc sensor-id="
            << id
            << " ! video/x-raw(memory:NVMM), format=NV12, width="
            << width
            << ", height="
            << height
            << " tee name=t t. ! nvvidconv ! video/x-raw, width="
                << width
                << ", height="
                << height
                << ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)"
                << sinkFormat
                << " ! videoconvert "
                << overlays
                << " ! appsink "
            << "t. ! nvv4l2h264enc insert-sps-pps=true ! h264parse ! rtph264pay pt=96 ! udpsink "
            << udpParams;
    }       
    else if(flags & CAM_APPSINK)
    {
       ss   << "nvarguscamerasrc sensor-id="
            << id
            << " ! video/x-raw(memory:NVMM), format=NV12, width="
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
    }
    GStString = ss.str();      
    this->cap = cv::VideoCapture(GStString);
}   
