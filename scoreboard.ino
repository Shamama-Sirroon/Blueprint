int green1 = 255;
int red1 = 255;
int blue1 = 255;
int green2 = 255;
int red2 = 255;
int blue2 = 255;
int color1 = 0;
int color2 = 0;
int stickUp = 0;
int stickDown = 800;
int realRed = 0;
int realGreen = 0;
int realBlue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP); 
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputZ1 = digitalRead(13);
  int inputY1 = analogRead(A1);
  int inputZ2 = digitalRead(A0);
  int inputY2 = analogRead(A2);
  Serial.println(inputZ1);
  Serial.println(inputZ2);

  //player 1
  
  if(inputZ1 == 0){
    color1++;
    digitalWrite(8, HIGH);
    //Serial.println("stick1");
    delay(500);
  } else {
    digitalWrite(8, LOW);
    //Serial.println("stick1 off");
  }
  //green control
  if(color1 % 3 == 0){
    if(inputY1 > 900 && green1 < 255){
      green1++;
    }
    if(inputY1 < 300 && green1 > 0){
      green1--;
    }
  }
  //red control
  if(color1 % 3 == 1){
    if(inputY1 > 900 && red1 < 255){
      red1++;
    }
    if(inputY1 < 300 && red1 > 0){
      red1--;
    }
  }
  //blue control
  if(color1 % 3 == 2){
    if(inputY1 > 900 && blue1 < 255){
      blue1++;
    }
    if(inputY1 < 300 && blue1 > 0){
      blue1--;
    }
  }

  //player 2

  if(inputZ2 == 0){
    color2++;
    digitalWrite(7, HIGH);
    //Serial.println("stick2");
    delay(500);
  } else {
    digitalWrite(7, LOW);
    //Serial.println("stick2 off");
  }
  //green control
  if(color2 % 3 == 0){
    if(inputY2 > 900 && green2 < 255){
      green2++;
    }
    if(inputY2 < 300 && green2 > 0){
      green2--;
    }
  }
  //red control
  if(color2 % 3 == 1){
    if(inputY2 > 900 && red2 < 255){
      red2++;
    }
    if(inputY2 < 300 && red2 > 0){
      red2--;
    }
  }
  //blue control
  if(color2 % 3 == 2){
    if(inputY2 > 900 && blue2 < 255){
      blue2++;
    }
    if(inputY2 < 300 && blue2 > 0){
      blue2--;
    }
  }
  delay(10);

  analogWrite(11, red1);
  analogWrite(10, green1);
  analogWrite(9, blue1);
  analogWrite(6, red2);
  analogWrite(5, green2);
  analogWrite(3, blue2);

  realRed = analogRead(A3);
  realGreen = analogRead(A4);
  realBlue = analogRead(A5);

  if(abs(red1 - realRed) <= 25 && abs(green1 - realGreen) <= 25 && abs(blue1 - realBlue <= 25)){
    digitalWrite(2, HIGH);
  }
  if(abs(red2 - realRed) <= 25 && abs(green2 - realGreen) <= 25 && abs(blue2 - realBlue <= 25)){
    digitalWrite(12, HIGH);
  }

}
