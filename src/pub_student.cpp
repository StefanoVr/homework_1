#include <stdio.h>
#include <sstream>
#include "ros/ros.h"
#include "homework_1/Studente.h"
#include <string>
#include <iostream>
#include "std_msgs/String.h"


// Main loop
int main(int argc, char **argv)
{
  // Initialize the node
  ros::init(argc, argv, "pub_student");
  ros::NodeHandle n;
  
  // Create a publisher
  ros::Publisher studente_pub = n.advertise<homework_1::Studente>("msg_dati", 1000);
  
  // Create a rate
  ros::Rate rate(1); // 1 message per second

  int count = 0;
  // Run our code in a loop until node is shutdown
  while (ros::ok())
  { 
    std_msgs::String msg;
    homework_1::Studente studente_info;
	

    
    // Load in message components
    studente_info.nome_studente = "Stefano";
    studente_info.eta = (uint8_t) 56;
    studente_info.corso = "Informatica";
    

    std::stringstream sc;
    sc << studente_info.nome_studente + " " + studente_info.corso + " " << (int) studente_info.eta;

    studente_info.testo_concat = sc.str();
    
    ROS_INFO("%s", studente_info.testo_concat.c_str());

    // Publish the message
    studente_pub.publish(studente_info);

    ros::spinOnce();
    
    // Sleep to fix loop rate
    rate.sleep();
    count++;
  }
return 0;
}
