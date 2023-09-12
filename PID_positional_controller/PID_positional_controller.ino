#define pinEncoderA 2 
#define pinEncoderB 3

int position=0;

const int motorPWM = 9;       // PWM pin for motor speed control
const int motorDirection = 8; // Digital pin for motor direction control

long previous_time=0;
float previous_error=0,eintegral=0;
void setup() {
  pinMode(pinEncoderA, INPUT_PULLUP);
  pinMode(pinEncoderB, INPUT_PULLUP);

  attachInterrupt(pinEncoderA, ISR_rotateClockWise, CHANGE);
  attachInterrupt(pinEncoderB, ISR_rotateAntiClockWise, CHANGE);

  pinMode(motorPWM, OUTPUT);       // Set motorPWM as output
  pinMode(motorDirection, OUTPUT); // Set motorDirection as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
    //set target position
    int target=1200;
    if(Serial.available()>0){
        target=Serial.parseInt();
    }
    float Kp=1,Kd=0.25,Ki=0;

    long current_time=millis();
    
    float deltaT=(float(current_time-previous_time))/1000.0;
    previous_time=current_time;

    int error=target-position;

    float dervT=(error-previous_error)/deltaT;

    eintegral+=error*deltaT;

    float control_signal=Kp*error+Kd*dervT+Ki*eintegral;

    //motor power
    controlMotor(control_signal);

    previous_error=error;

    Serial.print(target);
    Serial.print(" ");
    Serial.print(position);
    Serial.println();

}

void ISR_rotateClockWise(void){
	if(digitalRead(pinEncoderA)!=digitalRead(pinEncoderB))
      position++;
  else
      position--;
    //clockwise
}
 void ISR_rotateAntiClockWise(void){
 	if(digitalRead(pinEncoderA)== digitalRead(pinEncoderB))
      position++;
   	else
      position--;
}
void controlMotor(float speed) {
  if (speed < 0) {
    //motor Rotates in clockwise direction
    digitalWrite(motorDirection, LOW);
    //assign speed to the motor (must be +ve)
    analogWrite(motorPWM, min(-1 * speed,255));
  } else {
    //motor Rotates in anticlockwise direction
    digitalWrite(motorDirection, HIGH);
    //assign speed to the motor
    analogWrite(motorPWM, min(speed,255));
  }
}