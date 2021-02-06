/*Leony Angela 18219032*/
/*Digital Input Output*/
/* source : https://randomnerdtutorials.com/esp32-digital-inputs-outputs-arduino/ */

// set pin numbers
const int buttonPin = 2;  // the number for the pushbutton pin is GPIO2
const int ledPin =  5;    // the number for the LED pin is GPIO5

// variable for storing the pushbutton status
int buttonState = 0; //0 means not pressed

void setup() {
  Serial.begin(115200);
  // initialize the pushbutton pin you want to read as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin you want as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin); //read the input from the push button attached to the GPIO you defined
  Serial.println(buttonState); 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) { //being pushed
    // turn LED on
    digitalWrite(ledPin, HIGH); //the state for the ledPin is HIGH (ON)
  } else {
    // turn LED off
    digitalWrite(ledPin, LOW); //the state for the ledPin is LOW (OFF)
  }
}
