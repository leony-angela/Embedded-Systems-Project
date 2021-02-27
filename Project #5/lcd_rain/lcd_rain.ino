//Leony Angela
//inspired by https://medium.com/r/?url=https%3A%2F%2Fcreate.arduino.cc%2Fprojecthub%2Fjacoslabbert99%2Farduino-lcd-icons-custom-characters-548f38
// include the library code:
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

byte rain11[] = {
  B01110,
  B11110,
  B11111,
  B01101,
  B00001,
  B10010,
  B10010,
  B00100
};

byte rain12[] = {
  B00100,
  B01001,
  B01001,
  B10010,
  B10010,
  B00100,
  B00100,
  B01001
};

byte rain13[] = {
  B01110,
  B01111,
  B11111,
  B11111,
  B11110,
  B11001,
  B01001,
  B10010
};

byte rain14[] = {
  B10010,
  B00100,
  B00100,
  B01001,
  B01001,
  B10010,
  B10010,
  B00100
};

byte rain21[] = {
  B01110,
  B11110,
  B11111,
  B01100,
  B10001,
  B00010,
  B10010,
  B00100
};

byte rain22[] = {
  B00100,
  B00100,
  B01001,
  B01001,
  B10010,
  B10010,
  B00100,
  B00100
};

byte rain23[] = {
  B01110,
  B01111,
  B11111,
  B11111,
  B11110,
  B11000,
  B01001,
  B10010
};

byte rain24[] = {
  B10010,
  B00000,
  B00100,
  B00101,
  B01001,
  B01001,
  B10010,
  B10010
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.backlight();
  //creating all the characters
  lcd.createChar(1 , rain11); //Numbering should start at 1, not 0
  lcd.createChar(2 , rain12);
  lcd.createChar(3 , rain13);
  lcd.createChar(4 , rain14);
  lcd.createChar(5 , rain21);
  lcd.createChar(6 , rain22);
  lcd.createChar(7 , rain23);
  lcd.createChar(8 , rain24);   
}

void loop() {
    lcd.setCursor(0,0);
    lcd.print("rain");
    lcd.setCursor(7,0);
    lcd.write(1);
    lcd.setCursor(7,1);
    lcd.write(2);
    lcd.setCursor(8,0);
    lcd.write(3);
    lcd.setCursor(8,1);
    lcd.write(4);
    delay (500);
    lcd.clear();
    
    lcd.setCursor(2,0);
    lcd.print("rain");
    lcd.setCursor(12,0);
    lcd.print("rain");
    lcd.setCursor(7,0);
    lcd.write(5);
    lcd.setCursor(7,1);
    lcd.write(6);
    lcd.setCursor(8,0);
    lcd.write(7);
    lcd.setCursor(8,1);
    lcd.write(8);
    delay (500);
    lcd.clear();

    lcd.setCursor(0,1);
    lcd.print("go");
    lcd.setCursor(7,0);
    lcd.write(1);
    lcd.setCursor(7,1);
    lcd.write(2);
    lcd.setCursor(8,0);
    lcd.write(3);
    lcd.setCursor(8,1);
    lcd.write(4);
    delay (500);
    lcd.clear();

    lcd.setCursor(2,1);
    lcd.print("go");
    lcd.setCursor(12,1);
    lcd.print("away");
    lcd.setCursor(7,0);
    lcd.write(5);
    lcd.setCursor(7,1);
    lcd.write(6);
    lcd.setCursor(8,0);
    lcd.write(7);
    lcd.setCursor(8,1);
    lcd.write(8);
    delay (500);
    lcd.clear();
}
 
