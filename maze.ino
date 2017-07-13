void maze()
{
    ultraServo.write(90);
    delay(200);
    forward();
    Serial.println(sonar.ping_cm());
    delay(200);
    motorsOff();
    if((sonar.ping_cm() < 7) && (sonar.ping_cm() > 0))
    {
        ultraServo.write(0);
        delay(100);
        if((sonar.ping_cm() < 10) && (sonar.ping_cm() > 0))
        {
            reverse();
            delay(300);
            motorsOff();
            rightWheelForward();
            delay(300);
            motorsOff();
            Serial.println("left Turn");
        }
        else
        {
            ultraViewAll();
        }
    }
}
void ultraViewAll()
{
    ultraServo.write(0);
    delay(1000);
    ultraServo.write(90);
    delay(1000);
    ultraServo.write(180);
    //delay(2000);
}
void mazeForward()
{
      // set up both motors for forward direction
    digitalWrite(RPin1, HIGH);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, HIGH);
    digitalWrite(LPin2, LOW);
    analogWrite(enableR,140);
    analogWrite(enableL,155);
}
