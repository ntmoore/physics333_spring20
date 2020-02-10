// What will this produce?
void setup() {
  Serial.begin(9600);
  int i;
  char line[60];

  for (i = 0; i < 30; i+=3) {
    float x = i / 10.0;
    sprintf(line,
            "%d\t%d\t%d\t",
            i, i / 10, i % 10
           );
    Serial.print(line);
    Serial.println(x);
  }
}

void loop() {

}
