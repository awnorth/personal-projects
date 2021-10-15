// Andrew North - 10/12/2021
// This program sets pin 13 to alternatly output 5V then 0V changing every second.
// Pin 13 voltage is measured with A0 pin and recorded with the serialmonitor.
//With help from tutorial: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay



int analogPin = 0;
int val = 0;

int voltageState = LOW;

// Using "unsigned long" for variable holding time.
unsigned long previousMillis = 0;

// constants won't change
const long interval = 1000;   // interval at which to change voltage

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);    // set digital pin 13 as output
}

void loop() {
  // millis() function returns number of milliseconds sense the 
  // board started running the current sketch
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (voltageState == LOW) {
      voltageState = HIGH;
    } else {
      voltageState = LOW;
    }

    digitalWrite(13, voltageState);
  }
  
  val = analogRead(analogPin);   // analogRead returns an int (0 to 1023)
  Serial.println(val);
}
