/*Leony Angela 18219032*/
/* Exploration */
/* Digital Input Output : blinking sequencely with PUSH BUTTON */
/* ON and blinking sequencely until the button is released */
/* References  from NERD Tutorials  https://RandomNerdTutorials.com/esp32-digital-inputs-outputs-arduino/ , Arduino Forum */

// set pin numbers
const int buttonPin = 2;  // the number of the pushbutton pins
int led1 = 4; //attached to GPIO4
int led2 = 5; //attached to GPIO5
int led3 = 19; //attached to GPIO19
int led4 = 18; //attached to GPIO18

// variable for storing the pushbutton status
int buttonState = 0;

void setup() {
  Serial.begin(115200);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);    
  pinMode(led4, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                      // wait for 1/2 a second
    digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led2, HIGH);    // turn the LED on (HIGH is the voltage level)
    delay(500);                      // wait for 1/2 a second
    digitalWrite(led2, LOW);     // turn the LED off by making the voltage LOW
    digitalWrite(led3, HIGH);     // turn the LED on (HIGH is the voltage level)
    delay(500);                      // wait for 1/2 a second
    digitalWrite(led3, LOW);      // turn the LED off by making the voltage LOW
    digitalWrite(led4, HIGH);     // turn the LED on (HIGH is the voltage level)
    delay(500);                      // wait for 1/2 a second
    digitalWrite(led4, LOW);      // turn the LED off by making the voltage LOW
  } 
  else {
    // turn LED off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}
