# InverseKinContinuumRoboter
 
 
 ## InverseCalc
 This class contains the main. The two modes are "position to motorpos" or "curvature to motor pos"
 
 ## RControl
 A placeholder for ROS or similar systems. Can be ignored and is only called in the main as test
 
 ## AngleCalc
 
 Converts a 3D coordinate into a 2D coordinate with an angle. To simplify the influence of the two segments with each other we move the robot in a single plane. 
 
 ## RadiusCalc
Contains 3 classes. A forward kinematic, a gradient descent loop and a class which calls the loop from different starting point to avoid local minima. Afterwards the curvatures with the lowest distance to the target point are returned.
 
 ## MotorPos
 This class converts curvatures into cable lengths and then motor positions. Needs to be calibrated for each robot
