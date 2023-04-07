#include "RControl.h"
#include <string>

Rcontroller::Rcontroller(int nodehandle, int motor_out)
{
	motor = motor_out;
	name = nodehandle;
}

void Rcontroller::Publish_Control(int value) {
	
}
