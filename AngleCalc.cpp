#include "AngleCalc.h"
#include <math.h>


#define PI 3.14159265
//calculates the angle of a 2d plane to a original reference point 
double AngleGamma(double x_cor, double y_cor, double z_cor)
{

	double angle = atan2(y_cor, x_cor) * 180 / PI;
	if (angle < 0) {
		angle = 360 + angle;
	}
	return angle;
}
//takes 3 coordinates and reduces to a 2d plane
double* Make2DPoints(double x_cor, double y_cor, double z_cor)
{
	static double Points[2];
	Points[0] = sqrt(x_cor * x_cor + y_cor * y_cor);
	Points[1] = z_cor;
	return Points;

}
