float Kp = 0.07;
float Kd = 0.01;

int rightMaxSpeed  =  110;
int leftMaxSpeed   =  110;
int rightBaseSpeed =  80;
int leftBaseSpeed  =  80;
int lastError = 0;

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   12     // emitter is controlled by digital pin 12
#define NUM_SAMPLES_PER_SENSOR  8


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
// A7 left corner
// a0 right corner
//QTRSensorsRC qtrrc((unsigned char[]) {A7, A6, A5, A4, A3, A2, A1, A0},
//  NUM_SENSORS, TIMEOUT, EMITTER_PIN);
//unsigned int sensorValues[NUM_SENSORS];

QTRSensorsAnalog qtrrc((unsigned char[]) {A7, A6, A5, A4, A3, A2, A1, A0}, 
  NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];


void PID() {
  unsigned int sensors[NUM_SENSORS];
//  int position = qtrrc.readLine(sensors, QTR_EMITTERS_ON , 0);    //, QTR_EMITTERS_ON , 1
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensors[i]);
    Serial.print('\t');
  }
  int position = qtrrc.readLine(sensors);
  int error = position - 3500;
  
  Serial.println(error);

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed - motorSpeed;
  int leftMotorSpeed = leftBaseSpeed + motorSpeed;

  rightMotorSpeed = constrain(rightMotorSpeed, -rightMaxSpeed, rightMaxSpeed);
  leftMotorSpeed = constrain(leftMotorSpeed, -leftMaxSpeed, leftMaxSpeed);

  drive(leftMotorSpeed, rightMotorSpeed);

  Serial.println("");
  Serial.print("Left: ");
  Serial.print(leftMotorSpeed);
  Serial.print("   Right: ");
  Serial.println(rightMotorSpeed);
}
