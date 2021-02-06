/*Leony Angela 18219032*/
/*Analog Output using PWM Signal 3 LED*/
/* source : https://randomnerdtutorials.com/esp32-pwm-arduino-ide/ */

// the number of the LED pin
const int ledPin = 16;  // GPIO16
const int ledPin2 = 17; // GPIO17
const int ledPin3 = 5;  // GPIO5

// setting PWM properties
const int freq = 5000;    //5000 Hz is fine for an LED signal frequency
const int ledChannel = 0; //channel used to generate the signal
const int resolution = 8; //control the LED brightness (in bit resolution)
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  //specify where the signal will appear 
  ledcAttachPin(ledPin, ledChannel);
  ledcAttachPin(ledPin2, ledChannel);
  ledcAttachPin(ledPin3, ledChannel);
}
 
void loop(){
  // increase the LED brightness
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
