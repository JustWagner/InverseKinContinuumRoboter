#pragma once
#include <math.h>


double* GetRadia(double x_cor, double y_cor, double z_cor, const int RobotLength, const int Robotwidth);
double* ForwardKin(double curv1, double curv2, const int RobotLength, int curve_direction, int curve_direction2);
double* InverseKinLoop(double x_cor2D, double y_cor2D, double curv1, double curv2, const int RobotLength, int curve_direction, int curve_direction2);
double Distance_2D(double x_cor, double y_cor, double x_cor2, double y_cor2);
double Distance_3D(double x_cor1, double y_cor1, double z_cor1, double x_cor2, double y_cor2, double z_cor2);
