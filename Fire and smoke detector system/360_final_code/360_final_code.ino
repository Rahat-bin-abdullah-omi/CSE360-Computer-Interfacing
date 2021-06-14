#include<Servo.h>

 Servo motorservo;
 int red=6;
 int green=7;
 int buzzer=13;
 int smoke= 9;
 int flame=10;

 void setup(){
  pinMode (flame,INPUT);
  pinMode (smoke,INPUT);
  pinMode (red,OUTPUT);
  pinMode (green,OUTPUT);
  pinMode (buzzer,OUTPUT);
  Serial.begin(9600);
  motorservo.attach(8);
  motorservo.write(0);
}

 void loop(){
   int fvalue=digitalRead(flame);
   int svalue=digitalRead(smoke);
  
   //Serial.print(" Flame value: ");
   Serial.println(fvalue);
   //Serial.print(" Smoke value: ");
   Serial.println(svalue);

  if (svalue==HIGH or fvalue==HIGH )
  {
    //Serial.print(" WARNING !!! PLEASE EXIT FROM THIS AREA ");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    tone(buzzer, 1000, 200);
    motorservo.write(180);   
  }
 else
   {
     //Serial.print(" THIS AREA IS SAFE ");
     digitalWrite(red, LOW);
     digitalWrite(green, HIGH);
     motorservo.write(0);
     noTone(buzzer);
  }
  delay(500);
}
