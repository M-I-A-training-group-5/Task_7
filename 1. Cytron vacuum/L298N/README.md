# L298N

![cytron](https://lastminuteengineers.b-cdn.net/wp-content/uploads/arduino/L298N-Motor-Driver-Module-Pinout.png)

![VCC](https://img.shields.io/badge/VCC-red) pin powers the IC’s internal H-Bridge, `which drives the motors`. This pin accepts input voltages ranging from 5 to 12V.


![5V](https://img.shields.io/badge/5V-red) pin is taken from the arduino and used to power the logic circuitry within the L298N IC.

![GND](https://img.shields.io/badge/GND-brown) is the common ground pin.

## first motor

![OUT 1 & 2](https://img.shields.io/badge/OUT_1_&_2-orange) the output pins which are connected to the first motor


![IN1 & IN2](https://img.shields.io/badge/IN1_&_IN2-gree) controls direction of the motor as follows: 

| Input1 | Input2 | Spinning Direction | 
|---|---|---|
| Low(0) | Low(0) | Motor OFF |
| Low(0) | High(1) | Forward | 
| High(1) | Low(0) | Backward |
| High(1) | High(1) | Motor OFF |

![ENA](https://img.shields.io/badge/ENA-purple) controls the velocity using arduino PWM pin so if arduino PWM pins or can easily be used to turn on or off the motor by passing HIGH and LOW values 

## second motor <div style="color : red">(a repetition of motor 1 section)</div>

![OUT 3 & 4](https://img.shields.io/badge/OUT_3_&_4-yellow) the output pins which are connected to the second motor


![IN3 & IN4](https://img.shields.io/badge/IN3_&_IN4-gree) controls direction of the motor as follows: 

| Input1 | Input2 | Spinning Direction | 
|---|---|---|
| Low(0) | Low(0) | Motor OFF |
| Low(0) | High(1) | Forward | 
| High(1) | Low(0) | Backward |
| High(1) | High(1) | Motor OFF |

![ENB](https://img.shields.io/badge/ENB-purple) controls the velocity using arduino PWM pin so if arduino PWM pins or can easily be used to turn on or off the motor by passing HIGH and LOW values 

