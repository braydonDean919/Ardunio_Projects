// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "ArduinoGraphics.h";
#include "Arduino_LED_Matrix.h";
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(6,5);
ArduinoLEDMatrix matrix;

const int joystickX = A0;
const int joystickY = A1;
const int buttonA=2;
const int buttonB=3;

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
  matrix.begin();
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  // add some static text
  // will only show "UNO" (not enough space on the display)
  const char text[] = "UNO r4";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText();
  matrix.endDraw();
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  delay(2000);
}

void loop() {
  int x = analogRead(joystickX);
  int y = analogRead(joystickY);
  int a = !digitalRead(buttonA);
  int b = !digitalRead(buttonB);
  // Make it scroll!
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);
  // add the text
  if(bluetooth.available()){
    String data = bluetooth.readStringUntil('\n');
    data.trim();
    String text= "   "+data+"   ";
    bluetooth.println("Message Displayed");
    Serial.println(data);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
   if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    message.trim();
    bluetooth.println(message);
    String text= "   "+message+"   ";
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text);
    matrix.endText(SCROLL_RIGHT);
    matrix.endDraw();
   }
}