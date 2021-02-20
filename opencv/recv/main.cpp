#include <iostream>
#include <string>
#include <unistd.h>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        std::cout << "Usage: recv <host_ip> <portL> <portR>" << std::endl;
        return -1;
    }
    
    std::string host = argv[1];
    std::string portL = argv[2];
    std::string portR = argv[3];

    
    stringstream ss;
    ss << "udp://" << host << ":" << portL; 
    std::string addrL = ss.str(); //create string with address for left cam src
    ss.str(""); //clear stringstream

    ss << "udp://" << host << ":" << portR;
    std::string addrR = ss.str(); //create string with address for right cam src 

    cv::VideoCapture capL(addrL);
    cv::VideoCapture capR(addrR);

    cv::Mat frameL;
    cv::Mat frameR;

    std::cout << "Starting grabbing frames." << std::endl;

    while(1)
    {
        capL >> frameL;
        capR >> frameR;

        if(!frameL.empty()) cv::imshow("left", frameL);
        else std::cout << "LEFT FRAME BLANK!" << std::endl;
        
        if(!frameR.empty()) cv::imshow("right", frameR);
        else std::cout << "RIGHT FRAME BLANK! " << std:: endl;
        
        char ch = cv::waitKey(1)
        if(ch == 'q') break;
    } 
    
    return 0;
}
