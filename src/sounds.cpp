// Luc made this awful (amazing) thing

#include <ros/ros.h>
#include <sound_play/sound_play.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

const std::string sound_directory = "/home/lucbettaieb/ros_ws/src/sandbox/portal/turret_sounds/";

void sleepok(int t, ros::NodeHandle &nh)
{
	if(nh.ok())
		sleep(t);
}

std::string getRandomSound(){
	std::srand (std::time(NULL));
	double rand = (double) std::rand() / RAND_MAX;
	std::cout << rand << std::endl;
	if(rand <= .2)
		return "1.wav";
	else if(rand > .2 && rand <= .4)
		return "2.wav";
	else if(rand > .4 && rand <= .6)
		return "3.wav";
	else if(rand > .6 && rand <= .8)
		return "4.wav";
	else
		return "5.wav";
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "sounds");

	ros::NodeHandle nh;
	sound_play::SoundClient sc;

	sleepok(1, nh);

	while(nh.ok()){
		sc.startWave(sound_directory + getRandomSound());
		sleepok(900, nh); //sleep for fifteen minutes 900 seconds
	}
}