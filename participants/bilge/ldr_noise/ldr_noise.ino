// IO-2-Noise Workshop
// @Bilge

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
  Serial.println(lightValMapped);
  tone(speaker, lightValMapped);
  delay(lightVal);
  
  // put your main code here, to run repeatedly:

}
