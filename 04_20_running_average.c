long stored_T[10];
int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int t = analogRead(A0);
  stored_T[i] = t;
  int last_i = i - 1;
  if (last_i < 0) {
    last_i = 9;
  }
  int change_since_last = stored_T[i] - stored_T[i - 1];
  Serial.print("change since last read: ");
  Serial.println(change_since_last);
  i++;
  if (i == 10) {
    i = 0;
  }

  long sum = 0;
  int j;
  for (j = 0; j < 10; j++) {
    sum += stored_T[j];
  }
  float avg_t = sum / 10;
  Serial.print("average of last 10 reads: ");
  Serial.print(avg_t);
  Serial.print("\n\n");

  delay(5000);
}
