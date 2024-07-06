#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11
SoftwareSerial Bluetooth(rxPin, txPin);

#define RELAY_1 2 // Connect Relay 1 to digital pin 2 (IN2)
#define RELAY_2 3 // Connect Relay 2 to digital pin 3 (IN3)
#define RELAY_3 4 // Connect Relay 3 to digital pin 4 (IN4)

String data = "";

void setup() {
  pinMode(RELAY_1, OUTPUT); // Relay 1 (IN2) for bulb 1
  pinMode(RELAY_2, OUTPUT); // Relay 2 (IN3) for bulb 2
  pinMode(RELAY_3, OUTPUT); // Relay 3 (IN4) for power socket
  
  Serial.begin(115200);
  Serial.println("Arduino serial initialized");
  
  Bluetooth.begin(9600);
  Serial.println("Bluetooth software serial initialized");
}

void loop() {
  // Voice-controlled system using the same app
  // Voice recognition commands should be sent as numerical values
  
  if (Bluetooth.available() > 0) {
    int commandNum = Bluetooth.parseInt(); // Read the incoming numerical command
    
    Serial.print("Received command: ");
    Serial.println(commandNum);
    
    switch (commandNum) {
      case 1:
        Serial.println("Turning on bulb 1");
        digitalWrite(RELAY_1, HIGH); // Turn on Relay 1 (IN2) for bulb 1
        break;
      case 2:
        Serial.println("Turning off bulb 1");
        digitalWrite(RELAY_1, LOW); // Turn off Relay 1 (IN2) for bulb 1
        break;
      case 3:
        Serial.println("Turning on bulb 2");
        digitalWrite(RELAY_2, HIGH); // Turn on Relay 2 (IN3) for bulb 2
        break;
      case 4:
        Serial.println("Turning off bulb 2");
        digitalWrite(RELAY_2, LOW); // Turn off Relay 2 (IN3) for bulb 2
        break;
      case 5:
        Serial.println("Turning on power socket");
        digitalWrite(RELAY_3, HIGH); // Turn on Relay 3 (IN4) for power socket
        break;
      case 6:
        Serial.println("Turning off power socket");
        digitalWrite(RELAY_3, LOW); // Turn off Relay 3 (IN4) for power socket
        break;
      default:
        Serial.println("Invalid command received");
        break;
    }
  }
}
