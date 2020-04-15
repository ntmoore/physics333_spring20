/* on the arduino, have a wire that runs from digital 10
    simulate a button switch via poking 5v or GND with the
    loose wire.
*/
bool d10;
int num_flips = 0;
unsigned long t0;
unsigned long time_of_last_signal=millis();
void setup() {
  pinMode(10, INPUT);
  d10 = digitalRead(10);
  Serial.begin(115200);
  t0 = millis();
}

void loop() {
  if (d10 != digitalRead(10)) {
    // looks like pin 10 flipped from last measurment
    // also introducing a 100ms delay to do a simple debounce 
    // of the switch 
    if (!d10 && (millis()-time_of_last_signal)>100 ) {
      num_flips++;
      time_of_last_signal=millis();
    }
    d10 = !d10;
  }

  if (  (millis() - t0) > 1000) {
    t0 = millis();
    Serial.print(t0);
    Serial.print("\tnum_flips = ");
    Serial.println(num_flips);
  }
}
