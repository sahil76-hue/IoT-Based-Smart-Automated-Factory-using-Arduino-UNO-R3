#include <Servo.h>
Servo servo_5;
int smoke=0;

const int pir=10;



const int pingUltra=3;
const int smokePin=A0;
const int buzzer = 4;
const int fan=9;
const int light=6;

int temp =0;
const int tempsen=A1;
const int fanpi=7;

void setup()
{
  Serial.begin(9600);
  servo_5.attach(5);
  pinMode(smokePin, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(tempsen,INPUT);
  pinMode(fanpi,OUTPUT);
  pinMode(pir,INPUT);
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);
}

void loop()
{
  
  
  
  
  
  long duration, entryDis;
  
  pinMode(pingUltra,OUTPUT);
  digitalWrite(pingUltra, LOW);
  delayMicroseconds(2);
  digitalWrite(pingUltra, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingUltra,LOW);
  
  
  pinMode(pingUltra,INPUT);
  duration=pulseIn(pingUltra,HIGH);
  entryDis= microsecondsToCentimeters(duration);
  Serial.print("Entry Dis=");
  Serial.println(entryDis);
  if (entryDis < 30)
  {
    servo_5.write(90);
    delay(2000);
  }
  else
  {
    servo_5.write(0);
  }
  
  smoke = analogRead(smokePin);
  Serial.print("reading of smoke=");
  Serial.println(smoke);
  if (smoke>=210)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  
  temp =(-40 + 0.488155*(analogRead(tempsen) - 20));
  Serial.print("Reading of temperature= ");
  Serial.print(temp);
  Serial.println(".C");
  
  if(temp>= 30)
  {
    digitalWrite(fanpi,HIGH);
  }
  else
  {
    digitalWrite(fanpi,LOW);
  }
  int p = digitalRead(pir);
  
  if (p == HIGH)
  {
    digitalWrite(fan,HIGH);
    digitalWrite(light,HIGH);
  }
  else
  {
    digitalWrite(fan,LOW);
    digitalWrite(light,LOW);
  }   
}



long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
  
}
