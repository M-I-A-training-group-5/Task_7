/// @file pid_controller.ino
/// @brief A program that implements a PID controller for a flow meter and a suction mechanism.
/// @author Group 5

/// @class PIDController
/// @brief A class that represents a PID controller.
class PIDController {
  public:
    /// @brief A constructor that initializes the PID controller with the given parameters.
    /// @param kp The proportional gain.
    /// @param ki The integral gain.
    /// @param kd The derivative gain.
    /// @param sample_time The sample time in seconds.
    PIDController(float kp, float ki, float kd, float sample_time) {
      this->kp = kp; ///< Assign the proportional gain to the class member
      this->ki = ki; ///< Assign the integral gain to the class member
      this->kd = kd; ///< Assign the derivative gain to the class member
      this->sample_time = sample_time; ///< Assign the sample time to the class member
      previous_error = 0; ///< Initialize the previous error to zero
      integral = 0; ///< Initialize the integral term to zero
    }

    /// @brief A function that calculates the control signal for the PID controller.
    /// @param setpoint The desired value of the process variable.
    /// @param process_variable The current value of the process variable.
    /// @return The control signal for the PID controller.
    float calculate(float setpoint, float process_variable) {
      float error = setpoint - process_variable; ///< Calculate the error value
      integral += (error * sample_time); ///< Update the integral term
      float derivative = (error - previous_error) / sample_time; ///< Calculate the derivative term
      float output = kp * error + ki * integral + kd * derivative; ///< Calculate the output value
      previous_error = error; ///< Update the previous error value
      return output; ///< Return the output value
    }
    
  private:
    float kp; ///< Proportional gain
    float ki; ///< Integral gain
    float kd; ///< Derivative gain
    float sample_time; ///< Sample time in seconds
    float previous_error; ///< Previous error value
    float integral; ///< Integral term
};
