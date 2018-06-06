#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <std_msgs/String.h>
/*

void initializePose(double xPose, double yPose);

void poseMessageReceived(const std_msgs::String& msg) {
    
    std::string str = msg.data;

    std::string sub_str_1 = str.substr(0, 6);
    double xPose = atof(sub_str_1.c_str());

    std::string sub_str_2 = str.substr(7, 13);
    double yPose = atof(sub_str_2.c_str());

    std::cout << xPose << "good" << yPose;

    initializePose(xPose, yPose);
}*/


//int main(int argc, char **argv) {
  //  ros::init(argc, argv, "test_xiaoming");
   // ros::NodeHandle nh;

   // ros::Publisher pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1000);


   // ros::Subscriber sub = nh.subscribe("/qr_codes", 1000, &poseMessageReceived);
 /*  while(ros::ok()) {
        geometry_msgs::PoseWithCovarianceStamped start_pos;
        start_pos.header.frame_id = "map";
        start_pos.header.stamp = ros::Time::now();
        start_pos.pose.pose.position.x = -0.846684932709;
    start_pos.pose.pose.position.y = 0.333061099052;
    start_pos.pose.pose.position.z = 0.0;

    start_pos.pose.pose.orientation.x = 0.0;
    start_pos.pose.pose.orientation.y = 0.0;
    start_pos.pose.pose.orientation.z = -0.694837665627;
    start_pos.pose.pose.orientation.w = 0.719166613815;

    start_pos.pose.covariance[0] = 0.25;
    start_pos.pose.covariance[7] = 0.25;
    start_pos.pose.covariance[1:7] = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0] ;
    start_pos.pose.covariance[8:34] = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]; 
    start_pos.pose.covariance[35] = 0.06853891945200942;*/

    //pub.publish(start_pos);

//    }

    //ros::spin();
//}

#include <ros/ros.h>

class SubscribeAndPublish
{
public:

  void initializePose(double xPose, double yPose){

//ros::init(argc, argv, "test_xiaoming_another");
  //  ros::NodeHandle nh;

   // ros::Publisher pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1000);

    geometry_msgs::PoseWithCovarianceStamped start_pos;
    start_pos.header.frame_id = "map";
    start_pos.header.stamp = ros::Time::now();
    start_pos.pose.pose.position.x = xPose;
    start_pos.pose.pose.position.y = yPose;
    start_pos.pose.pose.position.z = 0.0;

    start_pos.pose.pose.orientation.x = 0.0;
    start_pos.pose.pose.orientation.y = 0.0;
    start_pos.pose.pose.orientation.z = 0.0;
    start_pos.pose.pose.orientation.w = 0.0;

    pub_.publish(start_pos);
}

  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1000);

    //Topic you want to subscribe
    sub_ = n_.subscribe("/qr_codes", 1000, &SubscribeAndPublish::callback, this);
  }

  void callback(const std_msgs::String& msg)
  {
     std::string str = msg.data;

    std::string sub_str_1 = str.substr(0, 6);
    double xPose = atof(sub_str_1.c_str());

    std::string sub_str_2 = str.substr(7, 13);
    double yPose = atof(sub_str_2.c_str());

    std::cout << xPose << "good" << yPose;

    initializePose(xPose, yPose);
    //.... do something with the input and generate the output...
    //pub_.publish(output);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subscribe_and_publish");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}




