#include "RadiusCalc.h"
#include "AngleCalc.h"
#include <math.h>
#include <iostream>

# define M_PI          3.141592653589793238462643383279502884L
//todo fix bug!!
double* GetRadia(double x_cor, double y_cor, double z_cor, const int RobotLength, const int Robotwidth) {
	

	double* PlainCoords;
	PlainCoords = Make2DPoints(x_cor, y_cor, z_cor);
	double Angle = AngleGamma(x_cor, y_cor, z_cor);

	double x_cor2D = PlainCoords[0];
	double y_cor2D = PlainCoords[1];


	double curv1 = 0.0000;
	double curv2 = 0.0000;
	int direction = 0;
	int direction2 = 0;
	double* cur_pos;
	cur_pos = ForwardKin(curv1, curv2, RobotLength, direction, direction2);
	double x_curr = cur_pos[0];
	double y_curr = cur_pos[1];

	double distance = Distance_2D(x_cor2D, y_cor2D, x_curr, y_curr);
	double* next;

	double start_distance = 0;


	next = InverseKinLoop(x_cor2D, y_cor2D, curv1, curv2, RobotLength, 0, 0);

	curv1 = next[0];
	curv2 = next[1];
	direction = next[2];
	direction2 = next[3];
	distance = next[4];
	std::cout << distance << "  distance\n";
	

	for (double i = 0; i < 0.012; i = i + 0.0001) {
		
		next = InverseKinLoop(x_cor2D, y_cor2D, curv1, curv2 + i, RobotLength, 0, 0);
		
		if (next[4] < distance) {
			curv1 = next[0];
			curv2 = next[1];
			direction = next[2];
			direction2 = next[3];
			distance = next[4];
			std::cout << distance << "  distance\n";
			
			
			
		}


	}

	for (double i = 0; i < 0.012; i = i + 0.0001) {

		next = InverseKinLoop(x_cor2D, y_cor2D, curv1, curv2 + i, RobotLength, 0, 180);

		if (next[4] < distance) {
			curv1 = next[0];
			curv2 = next[1];
			direction = next[2];
			direction2 = next[3];
			distance = next[4];
			std::cout << distance << "  distance\n";
			


		}


	}

	for (double i = 0; i < 0.012; i = i + 0.0001) {

		next = InverseKinLoop(x_cor2D, y_cor2D, curv1, curv2 + i, RobotLength, 180, 0);

		if (next[4] < distance) {
			curv1 = next[0];
			curv2 = next[1];
			direction = next[2];
			direction2 = next[3];
			distance = next[4];
			std::cout << distance << "  distance\n";
			


		}


	}

	for (double i = 0; i < 0.012; i = i + 0.0001) {

		next = InverseKinLoop(x_cor2D, y_cor2D, curv1, curv2 + i, RobotLength, 180, 180);

		if (next[4] < distance) {
			curv1 = next[0];
			curv2 = next[1];
			direction = next[2];
			direction2 = next[3];
			distance = next[4];
			std::cout << distance << "  distance\n";
			


		}


	}
	



	static double Radia[6];
	Radia[0] = curv1;
	Radia[1] = curv2;
	Radia[2] = direction;
	Radia[3] = direction2;
	Radia[4] = distance;
	Radia[5] = Angle;


	return (Radia);
}

double* InverseKinLoop(double x_cor2D, double y_cor2D, double curv1, double curv2, const int RobotLength, int curve_direction, int curve_direction2) {

	int direction = curve_direction;
	int direction2 = curve_direction2;
	double* cur_pos;
	cur_pos = ForwardKin(curv1, curv2, RobotLength, direction, direction2);
	double x_curr = cur_pos[0];
	double y_curr = cur_pos[1];

	double distance = Distance_2D(x_cor2D, y_cor2D, x_curr, y_curr);
	double* next;

	double start_distance = 0;
	
	
	while (distance != start_distance) {

		//std::cout << distance << "  distance\n";
		start_distance = distance;

		next = ForwardKin(curv1 + 0.0001, curv2, RobotLength, direction, direction2);
		if (Distance_2D(x_cor2D, y_cor2D, next[0], next[1]) < distance) {
			curv1 = curv1 + 0.0001;
			distance = Distance_2D(x_cor2D, y_cor2D, next[0], next[1]);
		}


		if (curv1 > 0) {
			next = ForwardKin(curv1 - 0.0001, curv2, RobotLength, direction, direction2);
			if (Distance_2D(x_cor2D, y_cor2D, next[0], next[1]) < distance) {
				curv1 = curv1 - 0.0001;
				distance = Distance_2D(x_cor2D, y_cor2D, next[0], next[1]);
			}
		}


	

		//std::cout << distance << "  distance\n";
		//std::cout << "  loop\n";





	}



	static double Curvs[5];
	Curvs[0] = curv1;
	Curvs[1] = curv2;
	Curvs[2] = direction;
	Curvs[3] = direction2;
	Curvs[4] = distance;
	return Curvs;

}

//takes 2 curvatures and 2 directions and gives a 2d point
double* ForwardKin(double curv1, double curv2, const int RobotLength, int curve_direction, int curve_direction2) {

	static double Points[2];


	double segment = RobotLength / 2;
	double RotAngle;

	double RadiDirection = curve_direction * M_PI / 180;
	double RadiDirection2 = curve_direction2 * M_PI / 180;

	RotAngle = (segment * curv1);
	



	double x1;
	double y1;
	if (curv1 == 0) {
		x1 = 0;
		y1 = segment;
	}
	else {
		x1 = (cos(RadiDirection) / curv1) * (1 - cos(curv1 * segment));
		y1 = sin(curv1 * segment) / curv1;
	}

	

	double x2;
	double y2;
	if (curv2 == 0) {
		x2 = 0;
		y2 = segment;
	}
	else {
		x2 = (cos(RadiDirection2) / curv2) * (1 - cos(curv2 * segment));
		y2 = sin(curv2 * segment) / curv2;
	}

	



	Points[0] = (x2 * cos(RotAngle * -cos(RadiDirection)) - y2 * sin(RotAngle * -cos(RadiDirection)) + x1);
	Points[1] = x2 * sin(RotAngle * -cos(RadiDirection)) + y2 * cos(RotAngle * -cos(RadiDirection)) + y1;


	return Points;
}





double Distance_2D(double x_cor1, double y_cor1, double x_cor2, double y_cor2) {


	return sqrt((x_cor1-x_cor2)*(x_cor1-x_cor2) + (y_cor1 - y_cor2) * (y_cor1 - y_cor2));
}

double Distance_3D(double x_cor1, double y_cor1, double z_cor1, double x_cor2, double y_cor2, double z_cor2) {


	return sqrt((x_cor1 - x_cor2) * (x_cor1 - x_cor2) + (y_cor1 - y_cor2) * (y_cor1 - y_cor2) + (z_cor1 - z_cor2) * (z_cor1 - z_cor2));
}