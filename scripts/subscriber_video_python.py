#!/usr/bin/env python3

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import rospy
import cv2

bridge = CvBridge()

def image_callback(msg):
    print("Received an Image ... ")

    cv2_img = bridge.imgmsg_to_cv2(msg, "bgr8")
    cv2.imshow("test", cv2_img)
    cv2.waitKey(20)
    
def main():
    rospy.init_node('subscriber_video_python')
    image_topic = "/camera/video"
    rospy.Subscriber(image_topic, Image, image_callback)
    rospy.spin()

if __name__ == '__main__':
    main()