#include "PID.h"

// Example usage

// Global variables

float kp = 0.6;  ///< Proportional gain
float ki = 1;  ///< Integral gain
float kd = .02;  ///< Derivative gain
float target_flow_rate = 90;  ///< Target flow rate in CFM
float sample_time = 0.1;  ///< Sample time in seconds
float deadzone = 0.01; ///< Deadzone for the flow rate error

PIDController pid_controller(kp, ki, kd, sample_time); ///< Create an instance of the PID controller

// Variables for flow meter and suction mechanism
float current_flow_rate = 0;  ///< Initial flow rate
float control_signal = 0;    ///< Control signal for the suction mechanism

unsigned long previous_time = 0; ///< Previous time value in milliseconds

/**
 * @brief setup function to setup Serial
 * 
 */
void setup() {
  // Initialize your hardware and libraries

  Serial.begin(9600);  // Initialize serial communication
}


void loop() {
  unsigned long current_time = millis(); // Get the current time value in milliseconds
  float delta_time = (current_time - previous_time) / 1000.0;  // Convert milliseconds to seconds and calculate the delta time

  if (delta_time >= sample_time) { // Check if the delta time is greater than or equal to the sample time
    // Measure the current flow rate using the flow meter
    // Update the current_flow_rate variable with the measured value

    // Calculate the control signal using the PID controller
    control_signal = pid_controller.calculate(target_flow_rate, current_flow_rate);

 
   
 if(abs(target_flow_rate-current_flow_rate) >= deadzone ){


         current_flow_rate += control_signal;
         Serial.print("Current flow rate: ");

        Serial.println(current_flow_rate);
   }
   else if(abs(target_flow_rate-current_flow_rate) <= deadzone ){

         return;
   }
         
   

    // Apply the control signal to the suction mechanism
    // Adjust the suction mechanism based on the control signal

    // Print the control signal
    

    previous_time = current_time; // Update the previous time value with the current time value
  }

}
