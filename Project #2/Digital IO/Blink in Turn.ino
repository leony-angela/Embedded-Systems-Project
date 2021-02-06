/*Leony Angela 18219032*/
/* Exploration */
/* Digital Input Output*/
/* blinking in turns */
/* Complete Instructions: https://RandomNerdTutorials.com/esp32-digital-inputs-outputs-arduino/ */
/* References  from NERD Tutorials, Arduino Forum */

// set pin numbers
const int buttonPin = 2;  // the number of the pushbutton pin in GPIO2
const int greenPin =  5;    // the number of the green LED pin in GPIO5
const int redPin = 4; //the number of red LED pin in GPIO4

// variable for storing the pushbutton status
int buttonState = 0; //0 means not pressed

void setup() {
  Serial.begin(115200);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn green LED on, red LED off
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    // turn green LED off, red LED on
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
}
