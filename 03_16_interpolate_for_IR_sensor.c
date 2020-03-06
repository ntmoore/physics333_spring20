/*  This is an example program that uses linear interpolation to map a 
 *   voltage from a SHARP IR distance sensor to a distance read by the sensor.
 *   Calibration data came from the spec sheet, grabbed via LoggerPro photo analysis.
 */
#define ANALOG_PIN 2
//#define FUNCTION_PRINTING
int reading;
unsigned int t0, t1;
float voltage, distance_cm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("time(ms),ADC,V,Temp(C),");
  t0 = millis();
}

void loop() {
  reading = analogRead(ANALOG_PIN);
  t1 = millis() - t0;

  voltage = 5.0 * reading / 1023.0;
  distance_cm = get_distance_SHARP_gp2y0a02yk(voltage);

  Serial.print(t1); Serial.print(",");
  Serial.print(reading); Serial.print(",");
  Serial.print(voltage); Serial.print(",");
  Serial.print(distance_cm); Serial.println(",");
  delay(1000);
}

float get_distance_SHARP_gp2y0a02yk(float v_in) {
  /* Using interpolation to estimate distance reported by
     a SHARP gp2y0a02yk IR distance sensor.  I used Logger Pro
     to pull points from figure 2 of the datasheet,
     https://www.sparkfun.com/datasheets/Sensors/Infrared/gp2y0a02yk_e.pdf
  */
  float dist;
  int i, j;
  float dv, slope, dx;
  float v_cal[15] = {0.475468313 , 0.492449324 , 0.532071683 , 0.583014717 , 0.622637076 ,
                     0.679240447 , 0.764145503 , 0.837729884 , 0.933955614 , 1.081124378 , 1.256594827 ,
                     1.567913365 , 2.020740329 , 2.530170665 , 2.784885832
                    };
  float d_cal[15] = {149.192463 , 139.3001346 , 130.013459  , 119.717362  , 109.4212651 ,
                     99.93270525 , 89.8384926  , 80.55181696 , 69.85195155 , 60.56527591 , 50.269179 ,
                     40.78061911 , 29.87886945 , 19.98654105 , 15.54508748
                    };
  int num_records = 15;

  if (v_in < v_cal[0]) {
    // voltage is too low for calibration, throw out
    dist = -1.0;
  } else if (v_in > v_cal[num_records - 1]) {
    // voltage is too high for calibration, throw out
    dist = -2.0;
  } else {
    // where does the incoming voltage lie? Use index j for this
    j = -1;
    for (i = 0; i < num_records - 1 && j == -1; i++) {
      // note, voltage data has been resorted as ascending
      if (v_cal[i] < v_in && v_in < v_cal[i + 1] )
        j = i;
      //data pair j is just above (higher) than the voltage coming in
    }
    dv = v_in - v_cal[j]; // should be a positive number
    slope = (d_cal[j + 1] - d_cal[j]) / (v_cal[j + 1] - v_cal[j]); // should be a negative number
    dx = dv * slope;
    dist = dx + d_cal[j];
#ifdef FUNCTION_PRINTING
    Serial.print("incoming voltage="); Serial.println(v_in);
    Serial.print("j="); Serial.println(j);
    Serial.print("bounding V = ");
    Serial.print(v_cal[j]); Serial.print(",");
    Serial.print(v_cal[j + 1]); Serial.println(",");
    Serial.print("bounding dist = ");
    Serial.print(d_cal[j]); Serial.print(",");
    Serial.print(d_cal[j + 1]); Serial.println(",");
    Serial.print("dv="); Serial.println(dv);
    Serial.print("slope="); Serial.println(slope);
    Serial.print("dx="); Serial.println(dx);
#endif
  }
  return dist;
}
