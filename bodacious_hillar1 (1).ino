#include <Keypad.h>
#include <Servo.h>

// --- Keypad Configuration ---
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 10}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// --- Component Setup ---
Servo myServo;
const String password = "1234"; 
String enteredCode = "";

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor
  myServo.attach(9);
  myServo.write(0); // Ensure locked position
  
  pinMode(11, OUTPUT); // Green LED
  pinMode(12, OUTPUT); // Red LED
  
  Serial.println("--- Intelligent Access Node Active ---");
  Serial.println("Please enter your 4-digit PIN:");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    enteredCode += key;
    Serial.print("*"); // Print asterisk for security
    
    if (enteredCode.length() == 4) {
      Serial.println(); // New line after 4 digits
      checkPassword();
    }
  }
}

void checkPassword() {
  if (enteredCode == password) {
    Serial.println("STATUS: Access Granted!");
    digitalWrite(11, HIGH); // Green ON
    myServo.write(90);      // Unlock
    delay(3000);            // Wait 3 seconds
    digitalWrite(11, LOW);
    myServo.write(0);       // Relock
    Serial.println("STATUS: Node Relocked.");
  } else {
    Serial.println("STATUS: Invalid Password! Try again.");
    digitalWrite(12, HIGH); // Red ON
    delay(2000);
    digitalWrite(12, LOW);
  }
  
  enteredCode = ""; // Reset for next attempt
  Serial.println("\nEnter PIN:");
}