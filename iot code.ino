#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int SensorPin = A0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  pinMode(2,INPUT);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  int fire = digitalRead(2);
  int gas = digitalRead(6);
  if (fire==HIGH){
    lcd.setCursor(0,0);
    lcd.print("FIRE FIRE FIRE ");
    lcd.setCursor(0,1);
    lcd.print("FIRE - EXT. ON");
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("              ");
    lcd.setCursor(0,1);
    lcd.print("                   ");
  }
  if (gas==HIGH){
    lcd.setCursor(0,2);
    lcd.print("GAS DETECTED");
  }
  else{
    lcd.setCursor(0,2);
    lcd.print("              ");
  }
  if (gas==HIGH || fire==HIGH){
    lcd.setCursor(0,3);
    lcd.print("POWER SUPPLY OFF");
    digitalWrite(5,HIGH);
    digitalWrite(7,HIGH);
  }
  else{
    lcd.setCursor(0,3);
    lcd.print("                   ");
    digitalWrite(5,LOW);
    digitalWrite(7,LOW);
  }
}

