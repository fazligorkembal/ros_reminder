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

    // Init ros node ...

    ros::init(argc, argv, "publisher_image_test");
    ros::NodeHandle nh;

    //get image transporter

    // init publisher ...
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("/camera/image", 1);





    //cv::imshow("Display Window", img);
    //cv::waitKey(0);

    ros::Rate loop_rate(1);

    while(nh.ok()){
        std::string image_path = "/home/gorkem/Downloads/test.jpg";
        cv::Mat img = cv::imread(image_path, CV_LOAD_IMAGE_COLOR);
        sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", img).toImageMsg();

        
        
        pub.publish(msg);
        ros::spinOnce();
        cout << "SENDED ..." << endl;
        loop_rate.sleep();
        
    }



}