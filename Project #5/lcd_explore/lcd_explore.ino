// Leony Angela
// include the library code:
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 

//string
String message1 = "Be healthy";
String message2 = "and take care";
String message3 = "of yourself.";
String message4 = "Be happy with";
String message5 = "the beautiful things that make you, you.";
String message6 = "-Beyonce";

//function scroll text
void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

byte Heart[8] = {0b00000,0b00000,0b01010,0b11111,0b11111,0b01110,0b00100,0b00000};

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.createChar(0, Heart);
}

void loop(){
  //1
  lcd.setCursor(0, 0);
  lcd.print(message1);
  lcd.blink();
  delay(1500);
  lcd.noBlink();

  //2
  lcd.setCursor(0, 1);
  lcd.print(message2);
  lcd.blink();
  delay(1500);
  lcd.clear();

  //3
  lcd.setCursor(0, 0);
  lcd.print(message3);
  lcd.blink();
  delay(1700);
  lcd.noBlink();

  //4
  lcd.setCursor(0, 1);
  lcd.print(message4);
  lcd.blink();
  
  delay(1500);
  lcd.clear();

  //6
  lcd.noBlink();
  lcd.setCursor(4, 1);
  lcd.print(message6);
  lcd.setCursor(0 ,1);
  lcd.write(0);
  lcd.setCursor(15 ,1);
  lcd.write(0);
  delay(1000);

  //scrolling
  lcd.noBlink();
  scrollText(0, message5, 400, lcdColumns);
  lcd.clear();
  delay(1500);
}
