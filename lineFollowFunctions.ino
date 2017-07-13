void lineFollow()
{
    rightSensor = analogRead(rightSensorPin);
    middleSensor= analogRead(middleSensorPin);
    leftSensor= analogRead(leftSensorPin);
    if(middleSensor > BLACKlimit)
    {
        neoPixelsGreen();
        forward1();
    }
    else if(leftSensor > BLACKlimit)
    {
        neoPixelsRed();
        rightWheelForward1();
    }
    else if(rightSensor > BLACKlimit)
    {
        neoPixelsBlue();
        leftWheelForward1();
    }
    else
    {
        forward1();
    }
}
void ductTape()
{
    rightSensor = analogRead(rightSensorPin);
    middleSensor= analogRead(middleSensorPin);
    leftSensor= analogRead(leftSensorPin);
    if((middleSensor > BLACKlimit)&&(leftSensor > BLACKlimit)&&(rightSensor > BLACKlimit))
    {
        neoPixelsGreen();
        forward1();
    }
    else if(leftSensor < BLACKlimit)
    {
        neoPixelsRed();
        leftWheelForward1();
    }
    else if(rightSensor < BLACKlimit)
    {
        neoPixelsBlue();
        rightWheelForward1();
    }
    else
    {
        forward1();
        leftWheelForward1();
        delay(100);
    }
}

