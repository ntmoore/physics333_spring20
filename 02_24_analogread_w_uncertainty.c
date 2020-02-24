unsigned long t1, t2, t_mid, dt; 
int sensorValue;
void setup() {
  Serial.begin(9600);
  Serial.println("t(ms),dt(ms),value(0-1023),voltage(0-5v),dv,");
}

void loop() {
  t1=millis();
  sensorValue = analogRead(A0);
  // Documentation https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
  t2=millis();
  dt=(t2-t1)/2;
  t_mid=(t2-t1)/2;

  Serial.print(t_mid);
  Serial.print(",");
  Serial.print(dt);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print(sensorValue*(5.0/1023.0));
  Serial.print(",");
  Serial.print((5.0/1023.0));
  Serial.print(",");
 
  delay(500);
}
