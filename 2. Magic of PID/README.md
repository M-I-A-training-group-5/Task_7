# PID Controller

## Brief
This code implements a PID (Proportional-Integral-Derivative) controller for a mechanism that adjusts the flow rate based on a target value. The code uses the Arduino platform and assumes that the hardware and libraries are properly initialized.

## Code Explanation
The code consists of four main parts: 

- Include Statement
---
The first line of the code includes the math library for mathematical functions abs():
        
    #include <math.h> // Include the math library for mathematical functions

This library is needed for functions such as `abs` (absolute value).


- Global Variables
---
The next part of the code declares and initializes some global variables that are used throughout the program:

The first four variables are constants that define the PID parameters (`kp`, `ki`, `kd`) and the target flow rate (`target_flow_rate`) in cubic feet per minute (CFM). These values can be changed according to your needs and preferences.

The next variable (`sample_time`) defines how often the PID controller calculates and applies the control signal in seconds. This value should be chosen based on your hardware capabilities and desired performance.

The next part of this section defines a class called `PIDController` that encapsulates all the logic and data related to the PID controller. The class has a constructor that takes four arguments: `kp`, `ki`, `kd`, and `sample_time`. These arguments are assigned to corresponding class member variables. The constructor also initializes two other class member variables: `previous_error` and `integral`. These variables store the previous error and the integral term of the PID controller, respectively.

The class also has a method called `calculate` that takes two arguments: `setpoint` and `process_variable`. These arguments represent the desired value and the measured value of the system output, respectively. The method calculates and returns a control signal based on these arguments and using a standard PID formula:

    output = kp * error + ki * integral + kd * derivative;

where `error` is calculated as:

    error = setpoint - process_variable;

`integral` is updated as:

    integral += (error * sample_time);

and `derivative` is calculated as:

    derivative = (error - previous_error) / sample_time;

The method also updates the `previous_error` variable with the current `error`.

The next part of this section creates an instance of the PIDController class and passes the global variables `kp`, `ki`, `kd`, and `sample_time` as arguments to the constructor. This instance is stored in a variable called `pid_controller`.

The last part of this section declares and initializes three more global variables: `current_flow_rate`, `control_signal`, and `previous_time`. These variables store the current flow rate measured by the flow meter, the control signal calculated by the PID controller, and the previous time in milliseconds, respectively.

- Setup Function

---

The next part of the code defines the setup function that runs once when the program starts:

        void setup() {
        // Initialize your hardware and libraries
        Serial.begin(9600); // Initialize serial communication
        }

This function initializes the hardware and libraries that are needed for the program. In this case, the only initialization that is done is for the serial communication. The function calls the `Serial.begin` method and passes 9600 as an argument. This sets the baud rate for serial communication to 9600 bits per second.

- Loop Function

---

The last part of the code defines the loop function that runs repeatedly after the setup function:

This function performs the main logic of the program. It first gets the current time in milliseconds by calling the `millis` function from the math library. It then calculates the elapsed time since the last loop iteration by subtracting the previous time from the current time and dividing by 1000. This converts milliseconds to seconds.

The function then checks if the elapsed time is greater than or equal to the sample time. If it is, it proceeds to execute the following steps:

- Measure the current flow rate using a flow meter device connected to your hardware. This step is not shown in detail in this code, but you can use any suitable sensor or library to get this value.

- Update the global variable current_flow_rate with the measured value.

- Calculate the control signal using the PID controller by calling its `calculate` method and passing `target_flow_rate` and current_flow_rate as arguments.

- Check if the absolute difference between `target_flow_rate` and `current_flow_rate` is less than 0.01. If it is, return 0 from this function. This means that you have reached your target flow rate and you do not need to adjust your suction mechanism anymore.

- If not, check if `target_flow_rate` is greater than `current_flow_rate`. If it is, increase `current_flow_rate` by adding `control_signal` to it. This means that you need to increase your suction power to reach your target flow rate.

- If not, check if `target_flow_rate` is less than `current_flow_rate`. If it is, decrease `current_flow_rate` by subtracting `control_signal` from it. This means that you need to decrease your suction power to reach your target flow rate.

- Apply the control signal to your suction mechanism by adjusting it based on your hardware specifications. This step is also not shown in detail in this code, but you can use any suitable actuator or library to do this.

- Print the control signal and the current flow rate to your serial monitor by calling `Serial.print` and `Serial.println` methods.

Update the global variable `previous_time` with the current time.

## Conclusion

This code demonstrates how to implement a PID controller