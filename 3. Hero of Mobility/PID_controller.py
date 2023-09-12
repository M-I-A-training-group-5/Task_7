import time

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

class PositionController:
    def __init__(self, pid_controller, tolerance=0.01):
        self.pid_controller = pid_controller
        self.tolerance = tolerance

    def control(self, X_setpoint, Y_setpoint):
        X_position_axis = []
        Y_position_axis = []
        Vx_position_axis = []
        Vy_position_axis = []

        # Simulate feedback (initial position)
        X_feedback = 0
        Y_feedback = 0
        previous_time = time.time()

        while True:
            current_time = time.time()
            delta_time = (current_time - previous_time)

            if delta_time >= self.pid_controller.sample_time:
                # Get control outputs
                PID_outputX, PID_outputY = self.pid_controller.update(X_setpoint, Y_setpoint, X_feedback, Y_feedback)

                # Get feedback
                X_feedback += PID_outputX
                Y_feedback += PID_outputY

                # Calculate velocity components
                Vx = (PID_outputX) / delta_time
                Vy = (PID_outputY) / delta_time

                # Update axes
                X_position_axis.append(X_feedback)
                Y_position_axis.append(Y_feedback)
                Vx_position_axis.append(Vx)
                Vy_position_axis.append(Vy)

                # Print the current position and velocity
                print(f"X: {X_feedback}, Y: {Y_feedback}")
                print(f"Vx: {Vx}, Vy: {Vy}")

                previous_time = current_time

                # Check if the setpoints are reached within the tolerance
                if abs(X_setpoint - X_feedback) <= self.tolerance and abs(Y_setpoint - Y_feedback) <= self.tolerance:
                    break

        return X_position_axis, Y_position_axis, Vx_position_axis, Vy_position_axis
