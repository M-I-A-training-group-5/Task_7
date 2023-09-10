# Cytron connection to motor documentation

# Brief about cytron

---

It’s a motor driver which mainly contains of 2 pins, one of which is a digital pin which controls motor’s direction **(CW or CCW)** and the other is an analog pin which controls motor’s speed.

# Code explanation

---

- The variable `motorPWM` is assigned the value 9, representing the PWM pin used for motor speed control.
- The variable `motorDirection` is assigned the value 8, representing the digital pin used for motor direction control.
- In the `setup()` function, the `pinMode()` function is used to set the `motorPWM` and `motorDirection` pins as outputs. The `Serial.begin(9600)` function initializes the serial communication at a baud rate of 9600.
- In the `loop()` function, the `Serial.available()` function checks if input is available from the serial monitor. If there is input available, the `Serial.parseInt()` function reads the input as an integer and assigns it to the `speed` variable. The `controlMotor()` function is then called with the `speed` value as an argument.
- The `controlMotor()` function takes the `speed` as a parameter and controls the motor's speed and direction based on the input. If the `speed` is less than 0, the motor rotates in a clockwise direction. If the `speed` is greater than or equal to 0, the motor rotates in an anticlockwise direction.

# Conclusion

---

The provided Arduino code allows you to control the speed and direction of a motor using the serial monitor. By understanding the code and the role of each component, you can modify it to suit your specific motor control requirements.