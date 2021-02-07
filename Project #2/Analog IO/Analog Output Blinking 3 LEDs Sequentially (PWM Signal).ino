/*Leony Angela 18219032*/
/* Exploration */
/*Analog Output using PWM Signal 3 LED*/
/* source : https://randomnerdtutorials.com/esp32-pwm-arduino-ide/ */


// the number of the LED pin
const int ledPin = 16;  // 16 corresponds to GPIO16
const int ledPin2 = 17; // 17 corresponds to GPIO17
const int ledPin3 = 5;  // 5 corresponds to GPIO5

// setting PWM properties
const int freq = 5000; //5000 Hz is fine for an LED signal frequency
const int ledChannel1 = 0; //channel used to generate the signal from LED1
const int ledChannel2 = 1; //channel used to generate the signal from LED2
const int ledChannel3 = 2; //channel used to generate the signal from LED3
const int resolution = 8; //control the LED brightness (in bit resolution)
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);
  ledcSetup(ledChannel3, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel1);
  ledcAttachPin(ledPin2, ledChannel2);
  ledcAttachPin(ledPin3, ledChannel3);
}
 
void loop(){
  //for first LED
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel1, dutyCycle);
    delay(10);
  }
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel1, dutyCycle);   
    delay(10);
  }
  //for second LED
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel2, dutyCycle);
    delay(10);
  }
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel2, dutyCycle);   
    delay(10);
  }
  //for third LED
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel3, dutyCycle);
    delay(10);
  }
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel3, dutyCycle);   
    delay(10);
  }
}
