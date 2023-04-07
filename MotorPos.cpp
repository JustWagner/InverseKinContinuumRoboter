#include <math.h>
#include "MotorPos.h"
#include <iostream>


# define M_PI          3.141592653589793238462643383279502884L

//Calculates the curvatures of the Cables and converts it into Calbe length
//Also calculates influence of curv1 on curv2 and vice versa
int* GetCableLength(double curv1, double curv2, int direction1, int direction2, int angle, const int width, const int legnth) {
	static int Cable[2];

	double curv1_1 = 1 / (1 / curv1 - 4.5);
	double curv2_1 = 1 / (1 / curv2 - 4.5);




	if (direction1 == direction2) {
		curv1_1 = curv1_1 - curv2_1;
		if (curv1_1 < 0) {
			curv1_1 = curv1_1 * -1;
			if (direction1 == 0) {
				direction1 = 180;
			}
			else {
				direction1 = 0;
			}
		}
	}
	else {
		curv1_1 = curv1_1 + curv2_1;
	}



	if (direction1 == direction2) {
		curv2_1 = curv2_1 - (curv1_1 * 0.01);
		if (curv2_1 < 0) {
			curv2_1 = curv2_1 * -1;
			if (direction2 == 0) {
				direction2 = 180;
			}
			else {
				direction2 = 0;
			}
		}
	}
	else {
		curv2_1 = curv2_1 + (curv1_1 * 0.01);
	}


	
	Cable[0] = (legnth / 2) / (1 + width * (curv1_1) / 2);
	
	Cable[1] = (legnth) / (1 + width * curv2_1 / 2);
	return (Cable);
}


//converts Cable length into motor position estimate
int* GetMotorPos(double curv1, double curv2, int direction1, int direction2, int angle, const int width, const int legnth) {



	int* cable_length;
	cable_length = GetCableLength(curv1, curv2, direction1, direction2, angle, width, legnth);
	static int MotorPos[4];
	//MotorPos[0] = ((legnth - (cable_length[0] * cos(direction1 * M_PI / 180))) / 0.009);
	//MotorPos[1] = ((legnth - (cable_length[1] * cos(direction1 * M_PI / 180))) / 0.009);

	int motor1;
	int motor2;
	int motor3;
	int motor4;

	motor1 = (((legnth / 2) - cable_length[0]) / 0.017) * cos(angle*2*M_PI/360);
	motor2 = (((legnth / 2) - cable_length[0]) / 0.017) * sin(angle * 2 * M_PI / 360);
	motor3 = (((legnth)-cable_length[1]) / 0.012) * cos(angle * 2 * M_PI / 360);
	motor4 = (((legnth)-cable_length[1]) / 0.012) * sin(angle * 2 * M_PI / 360);



	if (direction1 == 0) {
		MotorPos[0] = 1500 + motor1;
	}
	else {
		MotorPos[0] = 1500 - motor1;
	}
	if (direction1 == 0) {
		MotorPos[1] = 1500 + motor2;
	}
	else {
		MotorPos[1] = 1500 - motor2;
	}


	if (direction2 == 0) {
		MotorPos[2] = 1500 - motor3;
	}
	else {
		MotorPos[2] = 1500 + motor3;
	}
	if (direction2 == 0) {
		MotorPos[3] = 1500 - motor4;
	}
	else {
		MotorPos[3] = 1500 + motor4;
	}
	return (MotorPos);



}