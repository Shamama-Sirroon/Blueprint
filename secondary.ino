#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  int colorCount1 = 0;
  int colorCount2 = 0;
  int state1 = 0;
  int state2 = 0;
  String colorString1 = "";
  String colorString2 = "";
  long randomRed = 0;
  long randomBlue = 0;
  long randomGreen = 0;
  int winner = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  
  Serial.begin(9600);  
  randomSeed(analogRead(3));
  lcd.begin(16, 2);
  randomRed = random(0, 256);
  randomBlue = random(0, 256);
  randomGreen = random(0, 256);
}

void loop() {
  // put your main code here, to run repeatedly:
  state1 = digitalRead(A4);
  state2 = digitalRead(A5);
  Serial.println(colorCount1);
  Serial.println(colorCount2);
  if(state1 == 1){
    colorCount1++;
    delay(500); 
  }
  if(state2 == 1){
    colorCount2++;
    delay(500);
  }
  if(colorCount1 % 3 == 0){
    colorString1 = "Green ";
  }
  if(colorCount1 % 3 == 1){
    colorString1 = "Blue  ";
  }
  if(colorCount1 % 3 == 2){
    colorString1 = "Red  ";
  }
  
  lcd.setCursor(0, 0);
  lcd.print(colorString1);
  
  if(colorCount2 % 3 == 0){
    colorString2 = "  Red";
  }
  if(colorCount2 % 3 == 1){
    colorString2 = "Green";
  }
  if(colorCount2 % 3 == 2){
    colorString2 = " Blue";
  }
  lcd.setCursor(11, 0);
  lcd.print(colorString2);
  
  analogWrite(6, randomRed);
  analogWrite(5, randomGreen);
  analogWrite(3, randomBlue);

  analogWrite(A0, randomRed);
  analogWrite(A1, randomGreen);
  analogWrite(A2, randomBlue);
  
  
  if(digitalRead(2) == 1){
    lcd.setCursor(0, 0);
    lcd.print("      P1        ");
    lcd.setCursor(0, 1);
    lcd.print("      Wins      ");
    
  }
  if(digitalRead(4) == 1){
    lcd.setCursor(0, 0);
    lcd.print("      P2        ");
    lcd.setCursor(0, 1);
    lcd.print("      Wins      ");
    
  }
  
}
