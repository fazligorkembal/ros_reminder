  /*
   * OpenCV Example using ROS and CPP
   */

  // Include the ROS library
  #include <ros/ros.h>

  // Include opencv2
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
// Include CvBridge, Image Transport, Image msg
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    std::string video_path = "/home/gorkem/Downloads/test.mp4";
    cv::VideoCapture cap(video_path);

    if(!cap.isOpened()){
        std::cout << "ERROR opening video stream or file ..." << endl;
        return -1;
    }

    while (1){
        cv::Mat frame;
        cap >> frame;

        if(frame.empty())
            break;
        
        cv::imshow("test", frame);
        cv::waitKey(20);

    }

}