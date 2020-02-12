// what will this produce?
int pwr, i = 0;
#define out_pin 5

void setup() {
  Serial.begin(9600);
  pinMode(out_pin, OUTPUT);
}

void loop() {
  Serial.print(i);
  switch (i) {
    case 1:
      pwr = 32;
      break;
    case 2:
      pwr = 64;
      break;
    case 3:
      pwr = 128;
      break;
    default:
      pwr = 0;
      break;
  }
  Serial.print(" pwr = ");
  Serial.println(pwr);

  analogWrite(out_pin, pwr); // analogWrite values from 0 to 255 @ 0.98kHz (1.02ms period) on Uno pin 5
  delay(500);
  i++;
  if (i == 4)
    i = 0;
}
