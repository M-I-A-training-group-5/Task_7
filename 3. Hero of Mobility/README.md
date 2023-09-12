## Analysis of kinematic model

![WhatsApp Image 2023-09-12 at 17 45 40](https://github.com/M-I-A-training-group-5/Task_7/assets/143869492/d50bbcf6-fa36-411b-aa4b-226f16ff8e14)

The angle between the three wheels of the AGV is 120°, forming an equilateral triangle; thus, the distances from the center of the robot to the three wheels are equal.
V2, V1, and V3 are the linear speeds of the left, right, and rear wheels, respectively; L is the distance from the center of the vehicle to the center of the wheel.

## Explanation of code:
![Screenshot (375)](https://github.com/amira-2003/MIA_tasks/assets/143869492/e037bbe6-2588-4f3f-8c9f-ebee67175ebe)

1.we calculated the linear spead of each wheel and assumed radius of the three wheel is 0.05m

2.Defines some constants related to the robot's physical properties, 

such as the distance between the wheel and the vertical axis of the robot (R),

the assumed wheel radius (r), and the distance between the wheels (wheel_distance).

3. Defines a function named "calculate_AngularVelocity" that takes in three parameters:
Vx (velocity in the x-direction), Vy (velocity in the y-direction),
   
 and omega (angular velocity). This function calculates the angular velocities of three wheels based on the provided parameters
   
 and returns them as O1, O2, and O3.The kinematics equations for each wheel can be derived as follows:

 angular velcity of O1 = (-Vx * 0.5 + Vy * 0.833 + omega * R ) / r 
 
 angular velcity of wO2 = (-Vx * 0.5 - Vy * -0.833 + omega * R ) /r
 
 angular velcity of wO3 = (Vx + omega * R) /r 
 


![Screenshot (378)](https://github.com/amira-2003/MIA_tasks/assets/143869492/534f337c-7ce3-4f4e-9356-891155cf84f3)

 4.Defines another function named "mps_to_RPM" that converts a velocity value in meters per second (mps) to revolutions per minute (RPM) for a wheel.

It calculates the wheel RPM based on the wheel circumference and returns the result.

5.Initializes three instances of the CytronMotor class, representing the motors connected to M1, M2, and M3 respectively.

![Screenshot (379)](https://github.com/amira-2003/MIA_tasks/assets/143869492/0a1e8be1-3b45-4670-89c8-3ac2e68b123a)

Defines a function named "control_motors" that takes in a list of PWM values as input. This function iterates over the PWM values and performs the following tasks for each motor:

   a. Limits the PWM value within the acceptable range of -255 to 255.
   
   b. Determines the motor instance based on the index.
   
   c. Sets the motor speed and direction based on the sign of the PWM value. If the PWM is positive, it sets the speed, runs the motor in the clockwise direction. 
   
   If the PWM is negative, it sets the speed (absolute value), and runs the motor in the counter-clockwise direction.
   
   If the PWM is zero, it sets the speed to zero and stops the motor.

 ![Screenshot (380)](https://github.com/amira-2003/MIA_tasks/assets/143869492/30d92ec5-51a6-4ee9-9f91-78deee414304)
 
6.Converts a list of desired wheel velocities (in meters per second) to PWM values using the "mps_to_RPM" function.

7. Calls the "control_motors" function with the obtained PWM values to control the motors accordingly.

