void forward()
{
  // set up both motors for forward direction
    digitalWrite(RPin1, HIGH);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, HIGH);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,140);
    analogWrite(enableL,155);
}

void reverse()  // similar to forward test
{
   // set up both motors for reverse direction
    digitalWrite(RPin1, LOW);
    digitalWrite(RPin2, HIGH);
    digitalWrite(LPin1, LOW);
    digitalWrite(LPin2, HIGH);
    analogWrite(enableR,140);
    analogWrite(enableL,155);
}
void leftWheelForward()
{
    digitalWrite(RPin1, LOW);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, HIGH);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,150);
    analogWrite(enableL,150);
}
void rightWheelForward()
{
    digitalWrite(RPin1, HIGH);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, LOW);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,200);
    analogWrite(enableL,150);
}
void motorsOff()
{
    digitalWrite(RPin1, LOW);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, LOW);
    digitalWrite(LPin2, LOW);
}
void forward1()
{
  // set up both motors for forward direction
    digitalWrite(RPin1, HIGH);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, HIGH);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,140);
    analogWrite(enableL,155);
    delay(50);
    motorsOff();
}

void reverse1()  // similar to forward test
{
   // set up both motors for reverse direction
    digitalWrite(RPin1, LOW);
    digitalWrite(RPin2, HIGH);
    digitalWrite(LPin1, LOW);
    digitalWrite(LPin2, HIGH);
    analogWrite(enableR,140);
    analogWrite(enableL,140);
    delay(50);
    motorsOff();
}
void leftWheelForward1()
{
    digitalWrite(RPin1, LOW);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, HIGH);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,150);
    analogWrite(enableL,150);
    delay(50);
    motorsOff();
}
void rightWheelForward1()
{
    digitalWrite(RPin1, HIGH);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, LOW);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,200);
    analogWrite(enableL,150);
    delay(50);
    motorsOff();
}
