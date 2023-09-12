# PID positional controller

# System control block

---

As it’s known that our system elements are: Plant, controller, sensor, summing point.

So in our simulation we enter the targeted position and we take the feedback from the encoder which plays the role of sensor and provides me with the measured position, the plant in our system here is also represented by the motor and its driver and we compute the error:

$**[e(t)=targeted position-measured position]**$

![Screenshot 2023-09-12 131431.jpg](PID%20positional%20controller%202984ae17945242abaf7c5609a689ca09/Screenshot_2023-09-12_131431.jpg)

# PID controller

---

Our controller algorithm contains of 3 controllers which are p-controller, I-controller, D-controller where P-controller is responsible for error mitigation but it has some drawbacks which is treated by the I and D controllers which are responsible for smoothing out the response to reach the targeted position more faster.

If we increase the KP we could reach the desired output more faster but we are vulnerable to overshooting.

![Screenshot 2023-09-12 132019.jpg](PID%20positional%20controller%202984ae17945242abaf7c5609a689ca09/Screenshot_2023-09-12_132019.jpg)

# Code description

---

## Global variables

---

First we initialize variables of pins of the encoder and the position to zero, and also we define the PWM pin for the motor speed control and digital pin for the direction and we initialize the previous errors and e-integral to zero 

## Functions

---

controlMotor—>pre-defined in the previous task which drives the motor direction and speed

ISR_rotateClockWise,ISR_rotateAntiClockWise—>Functions demonstrates the position of the motor depending on speed sign.

### loop function:

first we must set the target variable by the user. Then we initializes the parameters Kp,Kd,Ki and calculating delta time (time change) using the equation:

$∆t = current time − previous time$ 

Then we compute the integration and derivative with estimate approximations:

$\frac{\partial e(t)}{\partial t}=\frac{(error-prev error)}{\Delta t}$

$∫e(t) dt$=$∫e(t) dt$+$error * \Delta t$

Here we are ready to compute the function of the control signal:

$u(t)=Kp*error+Kd*\frac{\partial e(t)}{\partial t}+Ki*∫e(t) dt$

this attenuating signal is then sent to function control motor to drive the motor until we reach out targeted position.