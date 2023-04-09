#include "AngleCalc.h"
#include "RadiusCalc.h"
#include "MotorPos.h"
#include "RControl.h"
#include <iostream>

int main()
{

   
    int x;
    int y;
    int z;
    double* testPoint;
    int* Cables;
    int* MotorPos;
    double* forwardPoint;
    const int Robot_length = 260;
    const int Robot_width = 9;


//Inverse Kinematic Mode

/**/
   
    int motorpos1;
    int motorpos2;
    bool warning = false;
   
   
    while (true) {
        std::cout <<"  enter coordinates x,y,z\n";
        std::cin >> x;
        std::cin >> y;
        std::cin >> z;
        testPoint = GetRadia(x, y, z, 260, 90);
        std::cout << testPoint[0] << "  Rad1\n";
        std::cout << testPoint[1] << "  Rad2\n";
        std::cout << testPoint[2] << "  direct1\n";
        std::cout << testPoint[3] << "  direct2\n";



        forwardPoint = ForwardKin(testPoint[0], testPoint[1], Robot_length, testPoint[2], testPoint[3]);
        std::cout << forwardPoint[0] << "  xFor\n";
        std::cout << forwardPoint[1] << "  yFor\n";

        Cables = GetCableLength(testPoint[0], testPoint[1], testPoint[2], testPoint[3], testPoint[5], Robot_width, Robot_length);
        std::cout << Cables[0] << "  Length1\n";
        std::cout << Cables[1] << "  Length2\n";
        MotorPos = GetMotorPos(testPoint[0], testPoint[1], testPoint[2], testPoint[3], testPoint[5], Robot_width, Robot_length);
        std::cout << MotorPos[0] << "  MotorPos1\n";
        std::cout << MotorPos[1] << "  MotorPos2\n";
        std::cout << MotorPos[3] << "  MotorPos2\n";
        std::cout << MotorPos[4] << "  MotorPos2\n";
        std::cout << testPoint[5] << "  Angle\n";
       
        motorpos1 = MotorPos[0];
        motorpos2 = MotorPos[1];

        if (motorpos1 < 500) {
            motorpos1 = 500;
            warning = true;
        }
        if (motorpos2 < 500) {
            motorpos2 = 500;
            warning = true;
        }
        if (motorpos1 > 2500) {
            motorpos1 = 2500;
            warning = true;
        }
        if (motorpos2 > 2500) {
            motorpos2 = 2500;
            warning = true;
        }
        if (warning == true) {
            std::cout << "  Maximum motor range exceeded\n";
        }

    }




//Forward Kinematic Mode

/*

  


   


    double c1;
    double c2;
    int motorpos1;
    int motorpos2;
    bool warning = false;
  
    while (true) {

        std::cout << "  enter curv1,curv2\n";
        std::cin >> c1;
        std::cin >> c2;
        forwardPoint = ForwardKin(c1, c2, Robot_length, 0, 180);
        std::cout << forwardPoint[0] << "  xFor\n";
        std::cout << forwardPoint[1] << "  yFor\n";
        Cables = GetCableLength(c1, c2, 0, 180, 0, Robot_width, Robot_length);
        std::cout << Cables[0] << "  Length1\n";
        std::cout << Cables[1] << "  Length2\n";
        MotorPos = GetMotorPos(c1, c2, 0, 0, 0, Robot_width, Robot_length);
        std::cout << MotorPos[0] << "  MotorPos1\n";
        std::cout << MotorPos[1] << "  MotorPos2\n";

        motorpos1 = MotorPos[0];
        motorpos2 = MotorPos[1];

        if (motorpos1 < 500) {
            motorpos1 = 500;
            warning = true;
        }
        if (motorpos2 < 500) {
            motorpos2 = 500;
            warning = true;
        }
        if (motorpos1 > 2500) {
            motorpos1 = 2500;
            warning = true;
        }
        if (motorpos2 > 2500) {
            motorpos2 = 2500;
            warning = true;
        }
        if (warning == true) {
            std::cout << "  Maximum motor range exceeded\n";
        }

    
        

    }

*/


    

   

    
    //testPoint = ForwardKin(3.141592653589793238462643383279502884L / 260, 3.141592653589793238462643383279502884L / 260, Robot_length, 0, 0);
  
    //std::cout << Distance_2D(0,0,3,4) << "  DistanceCheck\n";


}

