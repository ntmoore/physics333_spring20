#define analog_pin 0
#define FrickinHUGE 300
int read_time_ms = 12;
int i,num_reads;
int xvals[FrickinHUGE];
unsigned long t0;
float x_sum, x_square_sum;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read as much as possible within a set time interval (read_time_ms)
  t0 = millis();
  num_reads = 0;
  while ((millis() - t0) < read_time_ms) {
    xvals[num_reads] = analogRead(analog_pin);
    num_reads++;  // note this is an array and loop index
  }

  // compute average and uncertainty of the values read during this interval
  x_sum = 0;
  for (i = 0; i < num_reads; i++) {
    Serial.print(xvals[i]);
    Serial.print(",");
    x_sum += xvals[i];
  }
  
  Serial.print("\navg = ");
  float avg_x = x_sum / (float)num_reads;
  Serial.println(avg_x);

  float uncer_x;
  for (i = 0; i < num_reads; i++) {
    x_square_sum += sq(xvals[i]-avg_x);
  }
  uncer_x = sqrt(x_square_sum / (float)num_reads);
  
  Serial.print("uncertainty = ");
  Serial.println(uncer_x);
  Serial.print("num_reads = ");
  Serial.println(num_reads);
  
  // print out results
}
