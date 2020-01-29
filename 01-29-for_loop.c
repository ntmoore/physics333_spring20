int i, j;
void setup() {
  Serial.begin(9600);
}

void loop() {

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      Serial.print(i);
      Serial.print(j);
      Serial.print("\t");
    }
    Serial.print("\n");
  }
  Serial.println("\n");
  
  delay(2000);
}
