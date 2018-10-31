// IO-2-Noise Workshop
// @Bilge

#include "pitches.h"

int note[] = {NOTE_C1,
              NOTE_CS1,
              NOTE_D1,
              NOTE_DS1,
              NOTE_E1,
              NOTE_F1,
              NOTE_FS1 ,
              NOTE_G1  ,
              NOTE_GS1,
              NOTE_A1  ,
              NOTE_AS1 ,
              NOTE_B1 ,
              NOTE_C2 ,
              NOTE_CS2 ,
              NOTE_D2  ,
              NOTE_DS2 ,
              NOTE_E2  ,
              NOTE_F2  ,
              NOTE_FS2 ,
              NOTE_G2  ,
              NOTE_GS2 ,
              NOTE_A2  ,
              NOTE_AS2 ,
              NOTE_B2  ,
              NOTE_C3  ,
              NOTE_CS3 ,
              NOTE_D3 ,
              NOTE_DS3 ,
              NOTE_E3  ,
              NOTE_F3  ,
              NOTE_FS3 ,
              NOTE_G3  ,
              NOTE_GS3 ,
              NOTE_A3  ,
              NOTE_AS3 ,
              NOTE_B3  ,
              NOTE_C4  ,
              NOTE_CS4,
              NOTE_D4  ,
              NOTE_DS4 ,
              NOTE_E4  ,
              NOTE_F4  ,
              NOTE_FS4 ,
              NOTE_G4  ,
              NOTE_GS4 ,
              NOTE_A4  ,
              NOTE_AS4 ,
              NOTE_B4  ,
             };

int speaker = 12;
int LDR = A0;
int lightVal;
int lightValMapped;

void setup() {
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  lightVal = analogRead(LDR);
  lightValMapped = map(lightVal, 0, 1024, 30, 500);
  for (int i = 0; i < 47; i++) {
    if (lightValMapped > note[i] && lightValMapped <= note [i + 1]) {
      lightValMapped = note [i + 1];
    }
  }
  
  Serial.println(lightValMapped);
  tone(speaker, lightValMapped);
  delay(lightValMapped);

  // put your main code here, to run repeatedly:

}
