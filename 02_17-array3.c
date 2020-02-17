// what will this do?
void setup() {
  Serial.begin(9600);

  int x[3] = {1, 2, 3};
  int y[3] = {2, 2, -10};
  int res;

  res = dot(x, y);
  Serial.println(x);
  Serial.println(y);
  Serial.println(res);

}

void loop() {
}

int dot(int x[3], int y[3]) {
  int result = 0;
  for (int i = 0; i < 3; i++) {
    result += x[i] * y[i];
  }
  return result;
}
