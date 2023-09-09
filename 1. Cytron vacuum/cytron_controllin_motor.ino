const int motorPWM = 9;       // PWM pin for motor speed control
const int motorDirection = 8; // Digital pin for motor direction control

void setup() {
  pinMode(motorPWM, OUTPUT);       // Set motorPWM as output
  pinMode(motorDirection, OUTPUT); // Set motorDirection as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    int speed = Serial.parseInt();
    controlMotor(speed);
  }
}

void controlMotor(int speed) {
  if (speed < 0) {
    digitalWrite(motorDirection, LOW);
    analogWrite(motorPWM, -1 * speed);
  } else {
    digitalWrite(motorDirection, HIGH);
    analogWrite(motorPWM, speed);
  }
}