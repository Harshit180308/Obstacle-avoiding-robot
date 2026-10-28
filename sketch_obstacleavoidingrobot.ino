#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4); 

int trig = A0;
int echo = A1;

long duration;
int distance;
int leftdistance;
int rightdistance;


Servo myservo;

void setup()
{
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);  

  myservo.attach(9);
}

void loop()
{
  myservo.write(80);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo,HIGH);

  distance = duration*0.034/2;

  Serial.print("distance");
  Serial.println(distance);
  Serial.print("cm");

  if(distance <= 20)
  {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(600);
  myservo.write(20);

  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);

  rightdistance = duration*0.034/2;

  Serial.print("rightdistance");
  Serial.println(rightdistance);
  Serial.print("cm");

  myservo.write(160);

  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);

  leftdistance = duration*0.034/2;

  Serial.print("leftdistance");
  Serial.println(leftdistance);
  Serial.print("cm");
  
    if(leftdistance >= rightdistance)
    {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    }
    else
    {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  }
  else
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
}