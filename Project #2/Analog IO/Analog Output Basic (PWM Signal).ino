/*Leony Angela 18219032*/
/*Analog Output using PWM Signal*/
/* source : https://randomnerdtutorials.com/esp32-pwm-arduino-ide/ */

// the number of  LED pins the LED is attached to
const int ledPin = 16;  // LED 1 attached to GPIO16; corresponds to GPIO16 or RX 2 in ESP32

// setting PWM signal properties
const int freq = 5000;    //5000 Hz is fine for an LED signal frequency
const int ledChannel = 0; //channel used to generate the signal
const int resolution = 8; //control the LED brightness (in bit resolution)
 
void setup(){
  // configure LED PWM functionalitites using the properties above
  ledcSetup(ledChannel, freq, resolution); //
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel); //specify where the signal will appear 
}
 
void loop(){
  // increase the LED brightness from 0-255
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}
