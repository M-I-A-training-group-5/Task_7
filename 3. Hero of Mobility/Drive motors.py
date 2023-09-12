import math
import numpy as np
import time
from cytron import CytronMotor

R = 0.2  # Distance between the wheel and the vertical axis of the robot
r = 0.05  # Assumed wheel radius
wheel_distance = 0.2

arr = np.zeros(3)

def calculate_AngularVelocity(Vx, Vy, omega):
    O1 = (- Vx * 0.5 + Vy * 0.833 + omega * R ) / r 
    O2 = (- Vx * 0.5 - Vy * - 0.833 + omega * R ) /r
    O3 = ( Vx + omega * R) /r 
    return O1, O2, O3

def mps_to_RPM(mps):
    # Convert meters per second to revolutions per minute
    wheel_circumference = 2 * math.pi * r
    wheel_rpm = mps / wheel_circumference * 60
    return wheel_rpm

# Initializing   the Cytron motor drivers
motor1 = CytronMotor(1)  # Motor connected to M1
motor2 = CytronMotor(2)  # Motor connected to M2
motor3 = CytronMotor(3)  # Motor connected to M3

# Control the motors using Cytron motor drivers
# [5, 28., 90]
def control_motors(pwm_values):
    for i, pwm in enumerate(pwm_values): # This iterates the pwm on the array "pwm_values" each for loop iteration
        # Limit the PWM value to the acceptable range (-255 to 255)
        pwm = max(min(pwm, 255), -255)

        #
        if i == 0:
            motor = motor1
        elif i == 1:
            motor = motor2
        elif i == 2:
            motor = motor3

        # Determine the direction based on the sign of the PWM value
        if pwm > 0:
            motor.setSpeed(pwm)      # Set the speed
            motor.run(CytronMotor.CW)  # Run the motor in the clockwise direction
        elif pwm < 0:
            motor.setSpeed(-pwm)     # Set the speed (absolute value)
            motor.run(CytronMotor.CCW)  # Run the motor in the counter-clockwise direction
        else:
            motor.setSpeed(0)        # Set speed to 0 to stop the motor
            motor.run(CytronMotor.STOP)  # Stop the motor



# Define the wheel velocities in meters per second
wheel_velocities = [1.0, 1.5, 2.0]

# Converting the wheel velocities (m/s) to PWM values using the mps_to_RPM function
#by iterating on the wheel_velocities function and invoking it on every value
pwm_values = [mps_to_RPM(velocity) for velocity in wheel_velocities]

# Control the motors using the PWM values
control_motors(pwm_values)