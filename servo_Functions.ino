void oneDegree()
{
    if(currentServoPos1 <= 179)
    {
        currentServoPos1++;
        liftServo.write(currentServoPos1);
    }
    else
    {
        endServos();
    } 
    delay(200);
}
void fiveDegree()
{
    if(currentServoPos1 <= 175)
    {
        currentServoPos1+=5;
    }
    else
    {
        endServos();
    }
    liftServo.write(currentServoPos1);
    delay(200);
}
void oneDegreeDown()
{
    if(currentServoPos1 >= 1)
    {
        currentServoPos1--;
        liftServo.write(currentServoPos1);
    }
    else
    {
        homeServos();
    } 
    delay(200);
}
void fiveDegreeDown()
{
    if(currentServoPos1 > 5)
    {
        currentServoPos1-=5;
        liftServo.write(currentServoPos1);
    }
    else
    {
        homeServos();
    } 
    delay(200);
}
void homeServos()
{
    liftServo.write(0);
    currentServoPos1 = 0;
    delay(200);
}

void endServos()
{
    liftServo.write(180);
    currentServoPos1 = 180;
    delay(200);
}
void loadLauncher()
{
    launchServo.write(0);
}
void launch()
{
    launchServo.write(180);
}

