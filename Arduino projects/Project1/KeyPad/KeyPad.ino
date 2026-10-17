#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

// Define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect to the row pinouts of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 


Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
const int GREEN_PIN= 11;
const int RED_PIN = 10;
const String CORRECT_PASSWORD = "1234"; 
String eneteredPass = "";
void setup() {
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  Serial.println("System Ready. Enter Password:");
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY) {
    if (customKey == '#') {
        checkPassword();
      } 
     else if (customKey == '*') {
        eneteredPass = "";
        Serial.println("\nCleared. Try again:");
        flashLED(RED_PIN, 1, 200); 
      } else{
        eneteredPass += customKey;

      }
  }
}
void checkPassword(){
  Serial.println();
  eneteredPass.trim();


  if (eneteredPass == CORRECT_PASSWORD) {
    Serial.println("Access Granted!");
    digitalWrite(GREEN_PIN, HIGH);  
    digitalWrite(RED_PIN, LOW);     
    delay(3000);                    
    digitalWrite(GREEN_PIN, LOW);   
  } 
  else {
    Serial.println("Access Denied! Wrong Password.");
    digitalWrite(GREEN_PIN, LOW);   
    flashLED(RED_PIN, 3, 300);      
  }
  
  eneteredPass = ""; 
  Serial.println("Enter Password:");
}


void flashLED(int pin, int time, int dur){
  for (int i = 0; i < time; i++) {
    digitalWrite(pin, HIGH);
    delay(dur);
    digitalWrite(pin, LOW);
    delay(dur);
  }
}
