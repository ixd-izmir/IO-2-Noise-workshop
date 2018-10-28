/*
  ++ TONE from PROCESSING ++

  DESCRIPTION:
  Uses the tone library to generate a sound at a specific frequency, 500Hz by default.
  The tone function accepts two parameters: tone(pin, frequency).
  Change the frequency value to change the tone pitch!

  CIRCUIT:
  Connect a speaker or piezo to pin number 12 and to ground

  This example code is in the public domain.

  Author: Daniele Savasta based on Alessandro Contini Tone

 */

int speaker = 12;
int val;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(speaker, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available())
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
   }
  float freq = map(val,0,1000,100,5000);
  tone(speaker, freq);
}
