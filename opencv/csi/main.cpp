#include <iostream>
#include <string>
#include <unistd.h>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main(void)
{
    GStCamera cam(0, 1920, 1080, 30, (CAM_APPSINK | CAM_TIMEOVERLAY) "BGR");
    cv::VideoCapture vc = cam.cap;

    cv::Mat frame;

    cv::namedWindow("cam 0");
    for(;;)
    {
        vc >> frame;
        
        if(!frame.empty())
        {
            cv::imshow("cam 0", frame);
        }
      char ch = cv::waitKey(1);
      if(ch == 'q') break;
    }

}
