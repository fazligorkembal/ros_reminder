#!/usr/bin/env python3 
import rospy
from std_msgs.msg import String
import tensorflow
print(tensorflow.__version__)
def talker():
    pub = rospy.Publisher('test_message', String, queue_size=10)
    rospy.init_node("publisher_test_message", anonymous=True)
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        hello_str = "This is test message"
        rospy.loginfo("Sended ...")
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass