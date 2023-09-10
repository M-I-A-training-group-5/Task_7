const int motorPWM = 9;       // PWM pin for motor speed control
const int motorDirection = 8; // Digital pin for motor direction control

int currentSpeed = 0;
int targetSpeed = 0;

void setup()
{
  pinMode(motorPWM, OUTPUT);       // Set motorPWM as output
  pinMode(motorDirection, OUTPUT); // Set motorDirection as output

  Serial.begin(9600); // Initialize serial communication
}

void loop()
{
  if (Serial.available() > 0)
  {
    currentSpeed = targetSpeed;
    targetSpeed = Serial.parseInt();
    controlMotor();
  }
}

void controlMotor()
{
  if (targetSpeed < 0)
  {
    digitalWrite(motorDirection, LOW);
    targetSpeed = -targetSpeed;
    startFilter();
  }
  else
  {
    digitalWrite(motorDirection, HIGH);
    startFilter();
  }
}

void startFilter()
{
  double currentValue = currentSpeed;
  double targetValue = targetSpeed;
  double alpha = 0.04;

  while (currentValue < targetValue - 0.1) // Remove this
  {
    currentValue = (1.0 - alpha) * (double)currentValue + alpha * (double)targetValue;
    analogWrite(motorPWM, currentValue);
    Serial.println(currentValue);
    delay(20); // Remove this
  }
  currentSpeed = targetValue;
}
// implement delay to start filter func instead of delay(20)