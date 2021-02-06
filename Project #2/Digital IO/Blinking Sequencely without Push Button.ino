/*Leony Angela 18219032*/
/* Exploration */
/* Digital Output : blinking sequencely without PUSH BUTTON */
/* References  from NERD Tutorials  https://RandomNerdTutorials.com/esp32-digital-inputs-outputs-arduino/ , Arduino Forum */

int led1 = 4;
int led2 = 5;
int led3 = 19;
int led4 = 18;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);    
  pinMode(led4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(900);                      // wait for 1/2 a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(900);                      // wait for 1/2 a second
  digitalWrite(led2, LOW);     // turn the LED off by making the voltage LOW
  digitalWrite(led3, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(900);                      // wait for 1/2 a second
  digitalWrite(led3, LOW);      // turn the LED off by making the voltage LOW
  digitalWrite(led4, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(900);                      // wait for 1/2 a second
  digitalWrite(led4, LOW);      // turn the LED off by making the voltage LOW
}
