const int motorPWM = 9;       // PWM pin for motor speed control
const int motorDirection = 8; // Digital pin for motor direction control

void setup() {
  pinMode(motorPWM, OUTPUT);       // Set motorPWM as output
  pinMode(motorDirection, OUTPUT); // Set motorDirection as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  //Checking if there is available input from the serial
  if (Serial.available() > 0) {
    //Taking speed as input
    int speed = Serial.parseInt();
    controlMotor(speed);
  }
}
void controlMotor(int speed) {
  if (speed < 0) {
    //motor Rotates in clockwise direction
    digitalWrite(motorDirection, LOW);
    //assign speed to the motor (must be +ve)
    analogWrite(motorPWM, -1 * speed);
  } else {
    //motor Rotates in anticlockwise direction
    digitalWrite(motorDirection, HIGH);
    //assign speed to the motor
    analogWrite(motorPWM, speed);
  }
}