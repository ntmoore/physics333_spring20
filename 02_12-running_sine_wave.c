/* 
Here is a way to generate a sine wave that oscillates as time progresses.  
What frequency does the sine wave run at?  Are time units treated properly? 
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  unsigned long t0, t1, t_run;

  t0 = millis(); // start time
  int Tms = 400; // sine wave period in ms
  t1 = (millis() - t0) % Tms; // how far into a single wave are we?
  t_run = millis() - t0; // How long have we been making waves?
  int pwr;
  double w = 2.0 * acos(-1.0) / Tms;

  //  generate 3 periods
  while (t_run < 3 * Tms) {

    t_run = millis() - t0;
    t1 = (millis() - t0) % Tms;
    pwr = (int)(500.0 * (sin(w * t1) + 1.0));

    Serial.print(millis());
    Serial.print("\t");
    Serial.print(t1);
    Serial.print("\t");
    Serial.print(sin(w * t1) + 1, 7);
    Serial.print("\t");
    Serial.println(pwr);
  }
}

void loop() {
}
