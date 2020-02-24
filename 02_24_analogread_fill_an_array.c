unsigned long t1, t2, t_mid, dt;
float sum_v, avg_v;
#define NUM_READS 10
int i, sensorValue[NUM_READS];
void setup() {
  Serial.begin(9600);
  Serial.println("t(ms),dt(ms),value(0-1023),voltage(0-5v),dv,");
}

void loop() {
  t1 = millis();
  for (i = 0; i < NUM_READS; i++) {
    sensorValue[i] = analogRead(A0);
    // Documentation https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
  }
  t2 = millis();
  dt = (t2 - t1) / 2;
  t_mid = (t2 + t1) / 2;

  for (sum_v = 0.0, i = 0; i < NUM_READS; i++) {
    Serial.print(sensorValue[i]);
    Serial.print("\t");
    sum_v += (float)sensorValue[i];
  }
  Serial.println();
  avg_v = sum_v / (float)NUM_READS;

  Serial.print(t_mid);
  Serial.print(",");
  Serial.print(dt);
  Serial.print(",");
  Serial.print(avg_v);
  Serial.print(",");
  Serial.print(avg_v * (5.0 / 1023.0));
  Serial.print(",");
  Serial.print("????");  // note how should we specify the uncertainty in voltage read?
  Serial.println(",");

  delay(500);
}
