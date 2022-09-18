//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void sCalibrate() {
  digitalWrite(SCALLED, HIGH);
  
  int calibrateVariable = 7;       // should be devided by 5
//  int calibrateSpeed = 100;
  int calibrateSpeed = 80;

//  for (int i = 0; i < calibrateVariable; i++) {         // 50
//    if (i < calibrateVariable / 5) {                    // 10
//      drive(0, 0);
//    }
//    else if (i < 2 * calibrateVariable / 5) {           // 20
//      drive(-calibrateSpeed, calibrateSpeed);
//    }
//    else if (i < 4 * calibrateVariable / 5) {           // 40
//      drive(calibrateSpeed, -calibrateSpeed);
//    }
//    else {
//      drive(-calibrateSpeed, calibrateSpeed);
//    }
//    qtrrc.calibrate();
//    delay(10);
//  }
//  drive(0, 0);

  for (int i = 0; i < calibrateVariable; i++) {
    qtrrc.calibrate();
    drive(-120, 120);
    delay(10);
  }
  drive(0, 0);
  delay(100);

  for (int i = 0; i < 2 * calibrateVariable; i++) {
    qtrrc.calibrate();
    drive(120, -120);
    delay(10);
  }
  drive(0, 0);
  delay(100);

  for (int i = 0; i < calibrateVariable; i++) {
    qtrrc.calibrate();
    drive(-120, 120);
    delay(10);
  }
  drive(0, 0);
  delay(100);

  delay(2000);


  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  digitalWrite(SCALLED, LOW);
}
