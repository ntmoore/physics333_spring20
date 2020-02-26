void setup() {
  Serial.begin(9600);

  Serial.println(60001 / 30000);
  Serial.println(60001 % 30000);
  Serial.println();

  Serial.println((int)60001 / (int)30000);
  Serial.println((int)60001 % (int)30000);
  Serial.println();

  Serial.println((long)60001 / (long)30000);
  Serial.println((long)60001 % (long)30000);
  Serial.println();

  long top = 60001;
  long bottom = 30000;

  Serial.println(top / bottom);
  Serial.println(top % bottom);
  Serial.println();

  Serial.println((int)60001);
  
}

void loop() {
}
