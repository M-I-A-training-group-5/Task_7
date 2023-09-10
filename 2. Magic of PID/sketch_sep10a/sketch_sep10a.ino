class PIDController {
  public:
    PIDController(float kp, float ki, float kd, float sample_time) {
      this->kp = kp;
      this->ki = ki;
      this->kd = kd;
      this->sample_time = sample_time;
      previous_error = 0;
      integral = 0;
    }

    float calculate(float setpoint, float process_variable) {
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

// Example usage
float kp = 0.6;  // Proportional gain
float ki = 0;  // Integral gain
float kd = 0;  // Derivative gain
float target_flow_rate = 90;  // Target flow rate in CFM
float sample_time = 0.1;  // Sample time in seconds

// Create an instance of the PID controller
PIDController pid_controller(kp, ki, kd, sample_time);

// Variables for flow meter and suction mechanism
float current_flow_rate = 0;  // Initial flow rate
float control_signal = 0;    // Control signal for the suction mechanism

unsigned long previous_time = 0;
void setup() {
  // Initialize your hardware and libraries

  Serial.begin(9600);  // Initialize serial communication
}
void loop() {
  unsigned long current_time = millis();
  float delta_time = (current_time - previous_time) / 1000.0;  // Convert milliseconds to seconds

  if (delta_time >= sample_time) {
    // Measure the current flow rate using the flow meter
    // Update the current_flow_rate variable with the measured value

    // Calculate the control signal using the PID controller
    control_signal = pid_controller.calculate(target_flow_rate, current_flow_rate);

 
   
 
        current_flow_rate += control_signal;
        
        Serial.print("Current flow rate: ");
        Serial.println(current_flow_rate);
        
         
   

    // Apply the control signal to the suction mechanism
    // Adjust the suction mechanism based on the control signal

    // Print the control signal
  

    previous_time = current_time;
  }

}
