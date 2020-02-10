// what will this produce?
void setup() {
  Serial.begin(9600);
  int i = 0;
}

void loop() {
  Serial.print(i);
  i++;
}
