int pwr, incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(5, OUTPUT);
  pwr=0;
}

void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    // ignore if it is a newline
    Serial.print("you said: ");
    Serial.write(incomingByte);
    Serial.println();

    if (incomingByte != 10) {
      Serial.print("pwr level ");
      pwr = incomingByte;
      Serial.println(pwr);
      Serial.print("corrected: ");
      Serial.println(pwr - 48);
      pwr = pwr-48;
    }
  }
  Serial.print("Setting PWM power [0,255] to: 10*");
  Serial.println(pwr); 
  analogWrite(5,10*pwr);
  delay(1000);
}
