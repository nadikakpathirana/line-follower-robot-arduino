#include <QTRSensors.h>
#include "Variables.h"



void setup() {
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("BEGIN");

  // Motors
  pinMode(PWM0A, OUTPUT);
  pinMode(PWM0B, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // calibrate indictor
  pinMode(SCALLED, OUTPUT);

  sCalibrate();
}

void loop() {
  PID();
}
