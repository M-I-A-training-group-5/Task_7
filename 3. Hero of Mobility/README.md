# Hero of Mobility
# Overview
This project delves into the world of motor control and PID (Proportional-Integral-Derivative) based position and velocity control within the context of an Autonomous Planet Cleaner (APC). The primary goal is to offer a comprehensive understanding of omni wheels Kinematic, motor control, and how PID controllers can be harnessed for precise motion management.

- [Hero of Mobility](#hero-of-mobility)
- [Overview](#overview)
- [Motors control](#motors-control)
  - [Analysis of the kinematic model](#analysis-of-the-kinematic-model)
  - [Explanation of code:](#explanation-of-code)
- [PID controller](#pid-controller)
  - [`PID_controller.py`](#pid_controllerpy)
    - [PIDController class](#pidcontroller-class)
    - [PositionController class](#positioncontroller-class)
  - [`main.py`](#mainpy)
    - [animate\_position\_and\_speed function](#animate_position_and_speed-function)
  - [Usage](#usage)
- [Conclusion](#conclusion)

# Motors control

## Analysis of the kinematic model

![WhatsApp Image 2023-09-12 at 17 45 40](https://github.com/M-I-A-training-group-5/Task_7/assets/143869492/d50bbcf6-fa36-411b-aa4b-226f16ff8e14)

The angle between the three wheels of the AGV is 120°, forming an equilateral triangle; thus, the distances from the center of the robot to the three wheels are equal.
V2, V1, and V3 are the linear speeds of the left, right, and rear wheels, respectively; L is the distance from the center of the vehicle to the center of the wheel.

## Explanation of code:
![Screenshot (375)](https://github.com/amira-2003/MIA_tasks/assets/143869492/e037bbe6-2588-4f3f-8c9f-ebee67175ebe)

1. We calculated the linear speed of each wheel and assumed the radius of the three wheels is 0.05m

2. Defined some constants related to the robot's physical properties, 

such as the distance between the wheel and the vertical axis of the robot (R),

the assumed wheel radius (r), and the distance between the wheels (wheel_distance).

3. Defined a function named "calculate_AngularVelocity" that takes in three parameters:
Vx (velocity in the x-direction), Vy (velocity in the y-direction),
   
 and omega (angular velocity). This function calculates the angular velocities of three wheels based on the provided parameters
   
 and returns them as O1, O2, and O3. The kinematics equations for each wheel can be derived as follows:

 angular velcity of O1 = (-Vx * 0.5 + Vy * 0.833 + omega * R ) / r 
 
 angular velcity of wO2 = (-Vx * 0.5 - Vy * -0.833 + omega * R ) /r
 
 angular velcity of wO3 = (Vx + omega * R) /r 
 


![Screenshot (378)](https://github.com/amira-2003/MIA_tasks/assets/143869492/534f337c-7ce3-4f4e-9356-891155cf84f3)

 4. Defined another function named "mps_to_RPM" that converts a velocity value in meters per second (mps) to revolutions per minute (RPM) for a wheel.

It calculates the wheel RPM based on the wheel circumference and returns the result.

5. Initialized three instances of the CytronMotor class, representing the motors connected to M1, M2, and M3 respectively.

![Screenshot (379)](https://github.com/amira-2003/MIA_tasks/assets/143869492/0a1e8be1-3b45-4670-89c8-3ac2e68b123a)

Defines a function named "control_motors" that takes in a list of PWM values as input. This function iterates over the PWM values and performs the following tasks for each motor:

   a. Limits the PWM value within the acceptable range of -255 to 255.
   
   b. Determines the motor instance based on the index.
   
   c. Sets the motor speed and direction based on the sign of the PWM value. If the PWM is positive, it sets the speed and runs the motor in the clockwise direction. 
   
   If the PWM is negative, it sets the speed (absolute value), and runs the motor in the counter-clockwise direction.
   
   If the PWM is zero, it sets the speed to zero and stops the motor.

 ![Screenshot (380)](https://github.com/amira-2003/MIA_tasks/assets/143869492/30d92ec5-51a6-4ee9-9f91-78deee414304)
 
6. Converted a list of desired wheel velocities (in meters per second) to PWM values using the "mps_to_RPM" function.

7. Call the "control_motors" function with the obtained PWM values to control the motors accordingly.

# PID controller

This project demonstrates position and velocity control using a PID (Proportional-Integral-Derivative) controller. It includes two main files: `PID_controller.py` and `main.py`.

## `PID_controller.py`

This file contains the PID controller logic and the PositionController class.

### PIDController class

- `__init__(self, Kp, Ki, Kd, sample_time)`: Initializes the PID controller with the provided constants and sample time.

- `update(self, X_setpoint, Y_setpoint, X_feedback, Y_feedback)`: Updates the PID controller and calculates control outputs for X and Y based on the provided setpoints and feedback.

### PositionController class

- `__init__(self, pid_controller, tolerance=0.01)`: Initializes the PositionController with a PID controller and an optional tolerance value.

- `control(self, X_setpoint, Y_setpoint)`: Performs position control using the PID controller and returns X and Y position and velocity trajectories.

## `main.py`

This file handles the visualization of the position and velocity trajectories using Matplotlib.

### animate_position_and_speed function

- `animate_position_and_speed(X_position_axis, Y_position_axis, Vx_position_axis, Vy_position_axis)`: Creates an animated plot that displays the position trajectory and X/Y velocity trajectories.

## Usage

1. Set the PID controller constants (Kp, Ki, Kd) and the sample time in `main.py`.

2. Run `animation.py`.

3. Enter the desired position (x, y) when prompted.

4. The code will simulate the feedback control and display an animated plot showing the position and velocity trajectories.

# Conclusion
In this project, we explored motor control for an Autonomous Planet Cleaner (APC) using a kinematic model. We derived equations to calculate wheel angular velocities based on desired linear velocities and angular velocity.

We also implemented a control scheme for three motors to achieve the desired motion. Additionally, we introduced a PID (Proportional-Integral-Derivative) controller for position and velocity control, encapsulated in classes in PID_controller.py and utilized in main.py for visualization.

This project provides insights into motor control and PID-based control for robotic systems, offering a foundation for further enhancements and applications.