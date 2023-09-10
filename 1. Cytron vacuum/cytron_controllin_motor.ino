// Constants for pin assignments
const int motorPWM = 9;       // PWM pin for motor speed control
const int motorDirection = 8; // Digital pin for motor direction control

// Variables for motor control and filter parameters
double currentSpeed = 0;          // Current motor speed
double targetSpeed = 0;           // Target motor speed
const double alpha = 0.04;        // Smoothing factor for filtering
const int millisDelay = 20;       // Delay interval in milliseconds for applying the filter
unsigned long previousMillis = 0; // Stores the last time startFilter was called

void setup()
{
  pinMode(motorPWM, OUTPUT);       // Set motorPWM as an output
  pinMode(motorDirection, OUTPUT); // Set motorDirection as an output

  Serial.begin(9600); // Initialize serial communication
}

void loop()
{
  // Checking if there is available input from the serial
  if (Serial.available() > 0)
  {
    currentSpeed = targetSpeed;      // Update the current speed with the previous target speed
    targetSpeed = Serial.parseInt(); // Read the new target speed from serial input
  }

  unsigned long currentMillis = millis();
  // Call startFilter to filter the speed and motor control every 20 milliseconds (50 Hz)
  if (currentMillis - previousMillis >= millisDelay)
  {
    previousMillis = currentMillis;
    startFilter(); // Apply the filter and control the motor
  }
}

void startFilter()
{
  // Exponential smoothing filter to make motor speed changes gradual
  currentSpeed = (1.0 - alpha) * currentSpeed + alpha * targetSpeed;
  controlMotor(); // Control the motor based on the filtered speed
}

void controlMotor()
{
  if (currentSpeed < 0.0)
  {
    // Motor rotates in the clockwise direction (negative speed)
    digitalWrite(motorDirection, LOW);
    analogWrite(motorPWM, -currentSpeed); // Set motor speed
    Serial.print(-currentSpeed);          // Print the motor speed
    Serial.print(" clockwise");
    Serial.println();
  }
  else if (currentSpeed > 0.0)
  {
    // Motor rotates in the anticlockwise direction (positive speed)
    digitalWrite(motorDirection, HIGH);
    analogWrite(motorPWM, currentSpeed); // Set motor speed
    Serial.print(currentSpeed);          // Print the motor speed
    Serial.print(" anticlockwise");
    Serial.println();
  }
}
