#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pin8 = 8;
int analogPin = A0;    
int sensorValue = 0;     

//function to set up default status
void setup() {
  pinMode(analogPin, INPUT);
  pinMode(pin8, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("   Air Quality ");
  lcd.setCursor(0,1);
  lcd.print("MonitoringSystem ");
  Serial.begin(9600);
  lcd.display();
}

//function that determines the quality of the air
void loop() {
  
  delay(1000);
  sensorValue = analogRead(analogPin);     
  Serial.print("Air Quality in PPM = ");
  Serial.println(sensorValue);          
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("Air Quality: ");
  lcd.print (sensorValue);
  
  if (sensorValue<=500)
   {
   Serial.print("Fresh Air ");
   Serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Fresh Air");
   }
  else if( sensorValue>=500 && sensorValue<=650 )
   {
   Serial.print("Poor Air");
   Serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Poor Air");
   }
  else if (sensorValue>=650 )
   {
   Serial.print("Very Poor Air");
   Serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Very Poor Air");
   }
  //to determine when the alarm sets off
  if (sensorValue >650) {
    digitalWrite(pin8, HIGH);
  }
  else {
    digitalWrite(pin8, LOW);
  }
}
