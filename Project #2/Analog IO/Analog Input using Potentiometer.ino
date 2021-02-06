/*Leony Angela 18219032*/
/*Analog Input using Potentiometer*/
/* source : https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/ */

// In the module, Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 2; //I use GPIO2 which is corresponds to ADC2_CH2

// variable for storing the potentiometer value
int potValue = 0;

void setup() {
  Serial.begin(115200); //initiate a serial communication at baud rate 115200
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin); //read the analog input from the chose Pin
  Serial.println(potValue); //print the value from potentiometer in Serial Monitor
  delay(500);
}
