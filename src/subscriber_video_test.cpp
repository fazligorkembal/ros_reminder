#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

void  imageCallBack(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8") -> image);
        cv::waitKey(20);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber_video_test");
    ros::NodeHandle nh;
    cv::namedWindow("view");

    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("camera/video", 1, imageCallBack);
    std::cout << "LOADED ..." << std::endl;
    ros::spin();
    cv::namedWindow("view");
}