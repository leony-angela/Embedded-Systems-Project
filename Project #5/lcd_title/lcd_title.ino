/*********
Leony Angela / 18219032
Inspired by https://randomnerdtutorials.com  
*********/

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

String messageToScroll = "Playing with I2C LCD";

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

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  lcd.cursor();
  lcd.setCursor(0,0);
  lcd.print("p");
  delay(500);
  lcd.setCursor(1,0);
  lcd.print("r");
  delay(500);
  lcd.setCursor(2,0);
  lcd.print("o");
  delay(500);
  lcd.setCursor(3,0);
  lcd.print("j");
  delay(500);
  lcd.setCursor(4,0);
  lcd.print("e");
  delay(500);
  lcd.setCursor(5,0);
  lcd.print("c");
  delay(500);
  lcd.setCursor(6,0);
  lcd.print("t");
  delay(500);
  lcd.setCursor(7,0);
  lcd.print(" ");
  delay(500);
  lcd.setCursor(8,0);
  lcd.print("#");
  delay(500);
  lcd.setCursor(9,0);
  lcd.print("5");
  delay(500); 
  lcd.setCursor(10,0);
  lcd.print(":");
  delay(1200);
  lcd.noCursor();
  scrollText(1, messageToScroll, 500, lcdColumns);
  lcd.clear();
  delay(1500);
}
