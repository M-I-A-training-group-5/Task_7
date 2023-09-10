# Cytron Motor Controller using Exponential smoothing Filter

## Introduction

This documentation provides an overview of the code used to control a motor using a Cytron motor driver, including the implementation of an Exponential Smoothing Filter for precise motor speed control

# Brief about cytron

It’s a motor driver which mainly contains of 2 pins, one of which is a digital pin which controls motor’s direction **(CW or CCW)** and the other is a PWP pin which controls motor’s speed.

## Code Overview

### Pin Configuration

- `motorPWM`: PWM pin (Pin 9) for motor speed control.
- `motorDirection`: Digital pin (Pin 8) for motor direction control.

### Global Variables

- `currentSpeed`: Current motor speed.
- `targetSpeed`: Target motor speed.
- `alpha`: Smoothing factor for filtering (used in exponential smoothing).
- `millisDelay`: Delay interval in milliseconds for applying the filter.
- `previousMillis`: Stores the last time the `startFilter` function was called.

### `setup()` Function

- Configures `motorPWM` and `motorDirection` pins as outputs.
- Initializes serial communication with a baud rate of 9600.

### `loop()` Function

- Checks if input is available from the serial monitor.
- If input is available, updates `targetSpeed` with the new value.
- Calls the `startFilter` function at a regular interval to control the motor.

### `startFilter()` Function

- Applies an exponential smoothing filter to make motor speed changes gradual.
- Updates `currentSpeed` based on the filter.
- Calls the `controlMotor` function to control the motor based on the filtered speed.

### `controlMotor()` Function

- Controls the motor's speed and direction.
- If `currentSpeed` is negative, the motor rotates clockwise.
- If `currentSpeed` is positive or zero, the motor rotates anticlockwise.

# Additional Simulation

For a more in-depth understanding of how the exponential smoothing filter works, you can refer to this [Jupyter Notebook](calculating freq and alpha.ipynb). This notebook includes a simulation that demonstrates the filter's behavior and its application to achieve precise control of a variable over time.

The Jupyter file contains Python code that simulates the behavior of the smoothing filter, allowing you to visualize how it affects a variable's response to changes in a target value. It provides a complementary perspective to the Arduino code presented above.


## Conclusion

The provided Arduino code allows you to control the speed and direction of a motor using the serial monitor. The use of an exponential smoothing filter helps make speed transitions smooth and gradual, which can be beneficial in various applications.