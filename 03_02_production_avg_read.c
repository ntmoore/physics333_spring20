#define analog_pin 0
// how do you want the data to be reported?
//#define DEBUG_PRINT
#define PRODUCTION_PRINT

int read_time_ms = 12;
int i, num_reads;
unsigned long t0, t1, dt;
float xval, x_sum, x_square_sum;

void setup() {
  Serial.begin(9600);
#ifdef PRODUCTION_PRINT
  Serial.println("t(ms),dt(ms),<x>,<x^2>,N,sigma,");
#endif
}

void loop() {
  // read as much as possible within a set time interval (read_time_ms)
  num_reads = 0;
  x_sum = 0.0;
  x_square_sum = 0.0;
  t0 = millis();
  while ((millis() - t0) < read_time_ms) {
    xval = (float)analogRead(analog_pin);
#ifdef DEBUG_PRINT
    Serial.print(xval);
    Serial.print(",");
#endif
    x_sum += xval;  // sum to compute average
    x_square_sum += xval * xval; // sum to compute avg of squares, for sigma
    num_reads++;  // note this is an array and loop index
  }
  t1 = millis();
  dt = (t1 - t0) / 2;

  // compute average and uncertainty of the values read during this interval
  float avg_x = x_sum / (float)num_reads;
  float avg_square_x = x_square_sum / (float)num_reads;
  float sigma = sqrt(avg_square_x - avg_x * avg_x);

#ifdef DEBUG_PRINT
  Serial.println();
  Serial.print("At time (ms) ");
  Serial.print(t0 + dt);
  Serial.print(" +/- ");
  Serial.println(dt);
  Serial.print("<x> = ");
  Serial.println(avg_x);
  Serial.print("<x^2> = ");
  Serial.println(avg_square_x);
  Serial.print("num_reads = ");
  Serial.println(num_reads);
  Serial.print("sigma = ");
  Serial.println(sigma);
  Serial.println();
  delay(500);
#endif

#ifdef PRODUCTION_PRINT
  Serial.print(t0 + dt);
  Serial.print(",");
  Serial.print(dt);
  Serial.print(",");
  Serial.print(avg_x, 6);
  Serial.print(",");
  Serial.print(avg_square_x, 6);
  Serial.print(",");
  Serial.print(num_reads, DEC);
  Serial.print(",");
  Serial.print(sigma, 6);
  Serial.println(",");
#endif

}
