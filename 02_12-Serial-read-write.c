int incomingByte = 0; // for incoming serial data
char in;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.println("\nI received:");
    Serial.print("via write---");
    Serial.write(incomingByte);
    Serial.println("---");
    Serial.print("as DEC---");
    Serial.print(incomingByte,DEC);
    Serial.println("---");
    in = (char)incomingByte;
    Serial.print("as char---");
    Serial.print(in);
    Serial.println("---");
  }
}
/* reference: 
 *  https://en.wikipedia.org/wiki/ASCII
 *  http://www.asciitable.com/
 *  https://www.arduino.cc/reference/en/language/functions/communication/serial/write/
 */
