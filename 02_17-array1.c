// what will this do?
int i, x[10];
void setup() {
  Serial.begin(9600);
  for (i = 0; i < 5; i++) {
    x[i] = i;
  }
  for (i = 0; i < 15; i++) {
    Serial.print(i);
    Serial.print("\t");
    Serial.println(x[i]);
  }
}

void loop() {
}
