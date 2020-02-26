void setup() {
  Serial.begin(9600);

  float f_pi = acos(-1.0);
  double d_pi = acos(-1.0);

  Serial.println(f_pi);
  Serial.println(d_pi);

  Serial.println(f_pi, 20);
  Serial.println(d_pi, 20);

  f_pi = f_pi * 7.0;
  d_pi = d_pi * 7.0;

  f_pi = f_pi * (1.0 / 7.0);
  d_pi = d_pi * (1.0 / 7.0);

  Serial.println(f_pi, 20);
  Serial.println(d_pi, 20);

  for (int i = 2; i < 20; i++) {
    f_pi = f_pi * (float)i;
    d_pi = d_pi * (double)i;
  }
  for (int i = 2; i < 20; i++) {
    f_pi = f_pi * (1.0 / (float)i);
    d_pi = d_pi * (1.0 / (double)i);
  }
  Serial.println(f_pi, 20);
  Serial.println(d_pi, 20);
  // The Arduino isn't a normal c environment.  See https://www.arduino.cc/reference/en/language/variables/data-types/float/
  // specifically, only 6-7 digitas of precision.
}

void loop() {
}
