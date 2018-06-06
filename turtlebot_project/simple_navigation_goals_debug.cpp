#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

//typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

//int main(int argc, char** argv) {
  //  ros::init(argc, argv, "simple_navigation_goals");

    // tell the action client that we want to spin a thread by default
    //MoveBaseClient ac("move_base", true);

    // wait for the action server to come up
   // while(!ac.waitForServer(ros::Duration(5.0))) {
    //    ROS_INFO("Waiting for the move_base action server to come up");
   // }

    //move_base_msgs::MoveBaseGoal goal;
    
    // we'll send a goal to the robot to move 1 meter forward
    //goal.target_pose.header.frame_id = "map";
    //goal.target_pose.header.stamp = ros::Time::now();


    /*goal.target_pose.pose.position.x =  3.48180937767;
    goal.target_pose.pose.position.y =  2.02477455139;
    goal.target_pose.pose.position.z =  0.0;
    goal.target_pose.pose.orientation.x = 0.0;
    goal.target_pose.pose.orientation.y = 0.0;
    goal.target_pose.pose.orientation.z = 0.0;
    goal.target_pose.pose.orientation.w = 1.0;

    //goal.target_pose.pose.position.x = 1.0;
    //goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Hooray, the base moved 1 meter forward");
    else 
        ROS_INFO("The base failed to move forward 1 meter for some reason");

    return 0;*/
//}


// This program subscribes to turtle1/pose and shows its
// messages on the screen.

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <iomanip>   // for std::setprecision and std::fixed

bool moveToGoal(double xGoal, double yGoal);
// A callback function. Executed each time a new pose
// message arrives.

void poseMessageReceived(const std_msgs::String& msg) {
    
//ROS_INFO(msg);
    //std::string str = msg->data.c_str();

    std::string str = msg.data;

    std::string sub_str_1 = str.substr(0, 6);
    double xGoal = atof(sub_str_1.c_str());

    std::string sub_str_2 = str.substr(7, 13);
    double yGoal = atof(sub_str_2.c_str());

    std::cout << xGoal << "good" << yGoal;	

    //moveToGoal(xGoal, yGoal);
}

int main(int argc, char **argv) {
    // Initialize the ROS system and become a node.
    ros::init(argc, argv, "subscrib_to_qr_codes");
    ros::NodeHandle nh;

    // Create a subscirber object.
    ros::Subscriber sub = nh.subscribe("/qr_codes", 1000, &poseMessageReceived);

    // Let ROS take over
    ros::spin();
}   

bool moveToGoal(double xGoal, double yGoal) {
   //define a client for to send goal requests to the move_base server through a SimpleActionClient
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

   //wait for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
   }

   move_base_msgs::MoveBaseGoal goal;

   //set up the frame parameters
   goal.target_pose.header.frame_id = "map";
   goal.target_pose.header.stamp = ros::Time::now();

   /* moving towards the goal*/
   goal.target_pose.pose.position.x =  xGoal;
   goal.target_pose.pose.position.y =  yGoal;
   goal.target_pose.pose.position.z =  0.0;
   goal.target_pose.pose.orientation.x = 0.0;
   goal.target_pose.pose.orientation.y = 0.0;
   goal.target_pose.pose.orientation.z = 0.0;
   goal.target_pose.pose.orientation.w = 1.0;

   ROS_INFO("Sending goal location ...");
   ac.sendGoal(goal);
   ac.waitForResult();

   if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
      ROS_INFO("You have reached the destination");
      return true;
   }
   else{
      ROS_INFO("The robot failed to reach the destination");
      return false;
   }
}



















