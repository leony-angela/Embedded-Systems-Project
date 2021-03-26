#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "Aigoo";
const char* password = "Opaopa123";

WiFiServer server(80); // Set web server port number to 80
String header; // store the HTTP request

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";
const int output26 = 26; //GPIO26
const int output27 = 27; //GPIO27

unsigned long curr = millis(); // Current time
unsigned long prev = 0;  // Previous time
const long timeout = 2000; // timeout in milliseconds

void setup() {
  Serial.begin(115200);
  pinMode(output26, OUTPUT); // Initialize the variables as outputs
  pinMode(output27, OUTPUT);
  digitalWrite(output26, LOW); // Set outputs to LOW
  digitalWrite(output27, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();
  if (client) {                             // If a new client connects,
    curr = millis();
    prev = curr;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && curr - prev <= timeout) {  // loop while the client's connected
      curr = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><link rel=\"icon\" href=\"data:,\"><style>");
            client.println("html {background: linear-gradient(-45deg, #ebebbc, #e0d3ed);background-size: 400% 400%;animation: gradient 20s ease infinite;}");
            client.println("@keyframes gradient {0% {background-position: 0% 50%;}50% {background-position: 100% 50%;}100% {background-position: 0% 50%;}}");
            client.println("h1 { color: #36454F; font-family: Helvetica Neue,sans-serif;font-size: 45px; font-weight: 800; line-height: 72px; margin: 0 0 12px;text-align: center; text-transform: uppercase; }");
            client.println("p { color: #71797E; font-family: Oswald,sans-serif; font-size: 30px; font-weight: 500; line-height: 32px; text-align: center;margin: 12px 0 12px;text-transform: uppercase; }");
            client.println(".button1 input {opacity: 0;width: 0;height: 0;}");
            client.println(".button2 input {opacity: 0;width: 0;height: 0;}");
            client.println(".button1 {position: relative;display: inline-block;box-shadow: 0 .5rem 1rem rgba(0,0,0,.30);cursor: pointer;width: 100px;height: 50px;top: 0;left: 0;right: 0;bottom: 0;background-image: linear-gradient(to right, #93C572, #9bb4c2);border-radius: 34px;}");
            client.println(".button2 {position: relative;display: inline-block;box-shadow: 0 .5rem 1rem rgba(0,0,0,.30);cursor: pointer;width: 100px;height: 50px;top: 0;left: 0;right: 0;bottom: 0;background-image: linear-gradient(to right, #40826D, #356c87);border-radius: 34px;}");
            client.println(".button3 {position: relative;display: inline-block;box-shadow: 0 .5rem 1rem rgba(0,0,0,.30);cursor: pointer;width: 100px;height: 50px;top: 0;left: 0;right: 0;bottom: 0;background-image: linear-gradient(to right, #F08080, #db88a8);border-radius: 34px;}");
            client.println(".button4 {position: relative;display: inline-block;box-shadow: 0 .5rem 1rem rgba(0,0,0,.30);cursor: pointer;width: 100px;height: 50px;top: 0;left: 0;right: 0;bottom: 0;background-image: linear-gradient(to right, #CD5C5C, #981d61);border-radius: 34px;}");
            client.println(".slider1 {position: absolute;content: \"\";height: 40px;width: 40px;left: 5px;bottom: 5px;background-color: white;-webkit-transition: .4s;transition: .4s;border-radius: 50%;}");
            client.println(".slider2 {position: absolute;content: \"\";height: 40px;width: 40px;left: 55px;bottom: 5px;background-color: white;-webkit-transition: .4s;transition: .4s;border-radius: 50%;}");
            //client.println(".fix{width:200px;height:200px;position:fixed;bottom:-70px;right:-70px}");
            client.println("</style></head>");

            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            client.println("<p>" + output26State + "</p>"); // Display state buttons for GPIO 26  
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><label class=\"button1\"><span class=\"slider1\"></span></label></a></p>");
            } 
            else {
              client.println("<p><a href=\"/26/off\"><label class=\"button2\"><span class=\"slider2\"></span></label></a></p>");
            } 
               

            
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>" + output27State + "</p>"); // Display state buttons for GPIO 27     
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><label class=\"button3\"><span class=\"slider1\"></span></label></a></p>");
            } 
            else {
              client.println("<p><a href=\"/27/off\"><label class=\"button4\"><span class=\"slider2\"></span></label></a></p>");
            }
            client.println("</body>");
            //client.println("<img src=\"https://i.pinimg.com/originals/e4/2c/ce/e42cce6e492be5a2c6d10beb5f37280c.gif\" class=\"fix\"/>");
            client.println("</html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    client.stop(); // Close the connection
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
