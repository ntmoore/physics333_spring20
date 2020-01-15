// Use functions to show how to condense repeated code

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int i;
  for (i = 0; i < 100; i++) {
    blink(1, 9);
  }
  delay(500);
  for (i = 0; i < 100; i++) {
    blink(8, 2);
  }
  delay(500);
}

void blink(int on_length, int off_length) {

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(on_length);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(off_length);

  return;
}
