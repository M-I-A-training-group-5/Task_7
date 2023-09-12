class PIDController
{
public:
  PIDController(float kp, float ki, float kd, float sample_time)
  {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->sample_time = sample_time;
    previous_error = 0;
    integral = 0;
  }

  float calculate(float setpoint, float process_variable)
  {
    float error = setpoint - process_variable;
    integral += (error * sample_time);
    float derivative = (error - previous_error) / sample_time;
    float output = kp * error + ki * integral + kd * derivative;
    previous_error = error;
    return output;
  }

private:
  float kp;
  float ki;
  float kd;
  float sample_time;
  float previous_error;
  float integral;
};
