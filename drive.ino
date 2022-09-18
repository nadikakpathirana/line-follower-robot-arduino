//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void drive(int m1Speed, int m2Speed) {
  Serial.print("LM speed ");
  Serial.print(m1Speed);
  Serial.print("   ");
  Serial.print("RM speed ");
  Serial.println(m2Speed);
  
  // left motor
  // fixing moter error
  if (m1Speed > 0){
      setM1Speed(m1Speed - 11);
  } else if(m1Speed < 0) {
    setM1Speed(m1Speed + 12);
  }else{
    setM1Speed(m1Speed);
  }

  // right motor
  setM2Speed(m2Speed);
}

void setM2Speed(int speed) {
  if (speed > 0){
    // forward
    if (speed > 255){
      speed = 255;
    }
    digitalWrite(DIRB, LOW);
    analogWrite(PWM0B, speed);
  } else {
    //backword
    if (speed < -255){
      speed = -255;
    }
    digitalWrite(DIRB, HIGH);
    analogWrite(PWM0B, 255 - speed);
  }
}

void setM1Speed(int speed) {
  if (speed > 0){
    // forward
    if (speed > 255){
      speed = 255;
    }
    digitalWrite(DIRA, LOW);
    analogWrite(PWM0A, speed);
  } else {
    //backword
    if (speed < -255){
      speed = -255;
    }
    digitalWrite(DIRA, HIGH);
    analogWrite(PWM0A, 255 - speed);
  }
}
