// digital pin 2 has a pushbutton attached to it. Give it a name:
#define ROCK 2
#define PAPER 3
#define SCISSORS 4

int lastRock = 0;
int lastPaper = 0;
int lastScissors =0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(ROCK, INPUT_PULLUP);
  pinMode(PAPER, INPUT_PULLUP);
  pinMode(SCISSORS, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {
  int rockButtonState = digitalRead(ROCK);
  int scissorsButtonState = digitalRead(SCISSORS);
  int paperButtonState = digitalRead(PAPER);
if(rockButtonState == LOW and lastRock == HIGH){
    Serial.println("ROCK");
  }
  if(scissorsButtonState == LOW and lastScissors == HIGH){
    Serial.println("SCISSORS");
  }
  if(paperButtonState == LOW and lastPaper == HIGH){
    Serial.println("PAPER");
  }
  lastRock = rockButtonState;
  lastPaper = paperButtonState;
  lastScissors = scissorsButtonState;
  delay(1);  // delay in between reads for stability
}
