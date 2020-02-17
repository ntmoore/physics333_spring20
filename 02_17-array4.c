// what will this do?
void setup() {
  Serial.begin(9600);

  int x[3] = {1, 2, 3};
  int y[3] = {2, 2, 0};
  int res[3]={-100,-100,-100};

  cross(x, y, res);
  Serial.println(res[0]);
  Serial.println(res[1]);
  Serial.println(res[2]);

}

void loop() {
}

void cross(int a[3], int b[3], int c[3]) {
  c[2] = a[0]*b[1] - a[1]*b[0];
  c[1] = a[2]*b[0] - a[0]*b[2];
  c[0] = a[1]*b[2] - a[2]*b[1];
  return;
}
