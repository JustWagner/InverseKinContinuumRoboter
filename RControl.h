#pragma once
#include <string>


class Rcontroller
{
public:
		Rcontroller(int nodehandle, int motor_out);
		void Publish_Control(int value);
		int name;

private:

	std::string motor;
};
