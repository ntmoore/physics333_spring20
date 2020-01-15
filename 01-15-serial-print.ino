
int i;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  i=0;
}

// the loop routine runs over and over again forever:
void loop() {
  i=i+1;
  // print out a value:
  Serial.println(i
  );
  delay(1000);        // delay in between reads for stability
}
