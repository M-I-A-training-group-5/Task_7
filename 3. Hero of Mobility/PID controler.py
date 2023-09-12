import time

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Plotting code
# ...

class PIDController:
    def __init__(self, Kp, Ki, Kd, sample_time):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.sample_time = sample_time
        self.prev_error_X = 0
        self.prev_error_Y = 0
        self.integral_X = 0
        self.integral_Y = 0

    def update(self, X_setpoint, Y_setpoint, X_feedback, Y_feedback):
        # Calculate error for X and Y
        error_X = X_setpoint - X_feedback
        error_Y = Y_setpoint - Y_feedback

        # Calculate integral term for X and Y
        self.integral_X += error_X * self.sample_time
        self.integral_Y += error_Y * self.sample_time

        # Calculate derivative term for X and Y
        delta_error_X = (error_X - self.prev_error_X) / self.sample_time
        delta_error_Y = (error_Y - self.prev_error_Y) / self.sample_time

        # Calculate control outputs (Vx and Vy) using the PID formula
        PID_outputX = self.Kp * error_X + self.Ki * self.integral_X + self.Kd * delta_error_X
        PID_outputY = self.Kp * error_Y + self.Ki * self.integral_Y + self.Kd * delta_error_Y

        # Update previous error variables
        self.prev_error_X = error_X
        self.prev_error_Y = error_Y

        return PID_outputX, PID_outputY

if __name__ == "__main__":
    # Initialize PID controller with gains
    Kp = 0.2
    Ki = 0.0
    Kd = 0.01
    sample_time = 0.1
    tolerance = 0.01
    pid_controller = PIDController(Kp, Ki, Kd, sample_time)
    X_position_axis=[]
    Y_position_axis=[]
    # Set desired position
    X_setpoint, Y_setpoint = [float(x) for x in input("Enter position (x,y): ").split()]

    # Simulate feedback (initial position)
    X_feedback = 0
    Y_feedback = 0
    X_last_feedback = 0
    Y_last_feedback = 0
    previous_time = time.time()

    while True:
        current_time = time.time()
        delta_time = (current_time - previous_time)
    
        if delta_time >= sample_time:
            # Get control outputs
            PID_outputX, PID_outputY = pid_controller.update(X_setpoint, Y_setpoint, X_feedback, Y_feedback)

            # Get feedback
            X_feedback += PID_outputX
            Y_feedback += PID_outputY

            # Calculate velocity components
            Vx = (X_feedback - X_last_feedback) / delta_time
            Vy = (Y_feedback - Y_last_feedback) / delta_time

            # Update last feedback values
            X_last_feedback = X_feedback
            Y_last_feedback = Y_feedback
            X_position_axis.append(X_feedback)
            Y_position_axis.append(Y_feedback)

            # Print the current position
            print(f"X: {X_feedback}, Y: {Y_feedback}")
            print(f"Vx: {Vx}, Vy: {Vy}")

            previous_time = current_time

            # Check if the setpoints are reached within the tolerance
            if abs(X_setpoint - X_feedback) <= tolerance and abs(Y_setpoint - Y_feedback) <= tolerance:  # Corrected Y tolerance condition
                break

            # Plotting x and y analysis
    plt.figure(figsize=(8, 6))
    plt.plot(X_position_axis, Y_position_axis, 'b-', label='y = f(x)') 
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Analysis of x and y')
    plt.legend()

    # # Plotting vx and vy analysis
    # plt.figure(figsize=(8, 6))
    # plt.plot(vx, vy, 'r-', label='vy = f(vx)') 
    # plt.xlabel('vx')
    # plt.ylabel('vy')
    # plt.title('Analysis of vx and vy')
    # plt.legend()

    # Display the plots
    plt.show()
