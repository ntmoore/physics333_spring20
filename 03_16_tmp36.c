#define ANALOG_PIN 2
int reading;
unsigned int t0, t1;
float voltage, temp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("time(ms),ADC,V,Temp(C),");
  t0 = millis();
}

void loop() {
  // get data
  reading = analogRead(ANALOG_PIN);
  t1 = millis() - t0;

  // convert, 10bit 1024 state ADC
  voltage = 5.0*reading/1023.0;
  // using spec sheet conversion of
  // 10mV/C and intercept of-50C at 0V
  // https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf
  temp = voltage*(1/0.01)-50.0;
  
  Serial.print(t1); Serial.print(",");
  Serial.print(reading); Serial.print(",");
  Serial.print(voltage); Serial.print(",");
  Serial.print(temp); Serial.println(",");
  delay(1000);
}
