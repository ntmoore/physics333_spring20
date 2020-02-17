// this is the start of a music player
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  char a[3] = "a4";
  Serial.println(a);
  Serial.println(get_period(a));
}

void loop() {
  // play notes at 120bpm = 2 bps
  play_note(500, get_period("a3"), 10);
  play_note(500, get_period("b3"), 10);
  play_note(500, get_period("c3"), 10);
  play_note(500, get_period("d3"), 10);
  play_note(500, get_period("e3"), 10);
  play_note(500, get_period("f3"), 10);
  play_note(500, get_period("g3"), 10);

  delay(2000);
}

int play_note(int duration_ms, int tone_period_us, int out_pin) {
  unsigned int t0;
  t0 = millis();
  while ((millis() - t0) < duration_ms) {
    digitalWrite(out_pin, HIGH);
    delayMicroseconds(tone_period_us / 2);
    digitalWrite(out_pin, LOW);
    delayMicroseconds(tone_period_us / 2);
  }
  return;
}



int get_period(char note[3]) {
  int T;
  if (!strcmp(note, "b4")) {
    T = 2025;
  }
  else if (!strcmp(note, "a4")) {
    T = 2273;
  }
  else if (!strcmp(note, "g4")) {
    T = 2551;
  }
  else if (!strcmp(note, "f4")) {
    T = 2863;
  }
  else if (!strcmp(note, "e4")) {
    T = 3034;
  }
  else if (!strcmp(note, "d4")) {
    T = 3405;
  }
  else if (!strcmp(note, "c4")) {
    T = 3822;
  }
  else if (!strcmp(note, "b3")) {
    T = 4050;
  }
  else if (!strcmp(note, "bf3")) {
    T = 4290;
  }
  else if (!strcmp(note, "a3") ) {
    T = 4545;
  }
  else if (!strcmp(note, "g3") ) {
    T = 5102;
  }
  else if (!strcmp(note, "f3") ) {
    T = 5727;
  }
  else if (!strcmp(note, "e3") ) {
    T = 6068;
  }
  return T;
}
