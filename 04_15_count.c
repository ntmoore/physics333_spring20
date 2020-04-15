/* on the arduino, have a wire that runs from digital 10
 *  simulate a button switch via poking 5v or GND with the  
 *  loose wire.
 */
 bool d10;
int num_flips = 0;
unsigned int t0;
void setup() {
  d10 = digitalRead(10);
  Serial.begin(115200);
  t0 = millis();
}

void loop() {
  if (d10 != digitalRead(10)) {
    // looks like pin 10 flipped from last measurmenet
    num_flips++;
    d10 = !d10;
  }

  if (  (millis() - t0) > 1000) {
    t0=millis();
    Serial.print(t0); 
    Serial.print("\tnum_flips = ");
    Serial.println(num_flips);
  }
}
