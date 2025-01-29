# InverseKinContinuumRoboter

A model for a continuum robot powered by external motors attached to strings. The robot uses 4 motors for 2 segments. Segment 2 bends the entire robot and segment 1 the lower half. This class provides an approximation of the inverse kinematic by using gradient descent. The model only provides a simplified solution that bends the robot on a 2D plane to reach the selected point. Orientation of the end effector is ignored.
 
 
 ## InverseCalc
 This class contains the main. The two modes are "position to motorpos" or "curvature to motor pos". In the main width and length of the robot need to be specified.
 
 ## RControl
 A placeholder for ROS or similar systems. Can be ignored and is only called in the main as test
 
 ## AngleCalc
 
 Converts a 3D coordinate into a 2D coordinate with an angle. To simplify the influence of the two segments with each other we move the robot in a single plane.
 
 ## RadiusCalc
Contains 3 classes. A forward kinematic, a gradient descent loop and a class which calls the loop from different starting point to avoid local minima. Afterwards the curvatures with the lowest distance to the target point are returned.
 
 ## MotorPos
 This class converts curvatures and the angle into cable lengths and then motor positions. The angle is realized by distributing the required bending onto the 4 motors. This is achieved using cosinus and sinus.
 This class might require some calibration for any specific robot, since the robot this project was designed was still in early development and the strings changed positions throughout.
