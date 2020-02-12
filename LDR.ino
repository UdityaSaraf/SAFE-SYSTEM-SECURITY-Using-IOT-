#include<LiquidCrystal.h>
LiquidCrystal MyLCD(12,11,5,4,3,2);
const int LDR = A0;
int input_val = 0;
//const int LED = 2;
const int BUZZER = 6;
const int red = 8;
const int blue = 9;
const int green = 10;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
input_val = analogRead(LDR);
Serial.print("LDR VALUE IS: ");
Serial.println(input_val);
if(input_val>=13)
{
  for(int i=0;i<=10;i++)
  {
  digitalWrite(red,0);
  digitalWrite(blue,255);
  digitalWrite(green,255);
  delay(10);
  digitalWrite(BUZZER,HIGH);
  delay(150);
  digitalWrite(BUZZER,LOW);
  delay(100);
 
  MyLCD.begin(16,2);
  MyLCD.clear();
  MyLCD.home();
  MyLCD.print("ALERT!");
  MyLCD.setCursor(0,1);
  MyLCD.print("Safe Opened");
  for(int position=0;position<=17;position++)
  MyLCD.scrollDisplayRight();
  delay(100);
  for(int position=0;position<=34;position++)
  MyLCD.scrollDisplayLeft();
  delay(100);
  for(int position=0;position<=16;position++)
  MyLCD.scrollDisplayRight();
  delay(100);
  }
}
else
{
  digitalWrite(red,255);
  digitalWrite(blue,0);
  digitalWrite(green,255);
  digitalWrite(red,LOW);
  digitalWrite(BUZZER,LOW);
  MyLCD.begin(16,2);
  MyLCD.clear();
MyLCD.home();
  MyLCD.print("Safe Closed");
 /* for(int p=0;p<13;p++)
  MyLCD.scrollDisplayLeft();
  delay(200);
  for(int p=0;p<29;p++)
  MyLCD.scrollDisplayRight();
  delay(200);
  for(int p=0;p<16;p++)
  MyLCD.scrollDisplayLeft();
  delay(200);
  */
 }
delay(1000);
}
