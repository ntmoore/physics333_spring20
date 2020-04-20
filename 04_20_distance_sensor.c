/*
  HC-SR04 distance sensor
  Working off the example from:
    https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
  Spec sheet: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

  wiring connections:
  VCC - 5v
  Trig - "trigPin"
  Echo - "echopin"
  GND

  after a 10us pulse on trigPin, the device sends out 8x40kHz square pulse (sound wave).
  The device listens, and reports the travel time on echoPin
  details for reading echoPin with "pulseIn" here:
  https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/

*/

#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);  // make sure this pin is low!
}

void loop() {
  long pulse_length_us;
  float distance_m;

  // ask the sensor for a measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Listen for the result: Look for a LOW-HIGH-LOW pulse on echoPin
  pulse_length_us = pulseIn(echoPin, HIGH);
  // the speed of sound is ~ 340m/s
  // v_sound_m_p_us = 340 m/s * 1s/1e6us = 0.000340 m/us
  //distance_m = ( (float) pulse_length_us * 0.5 ) * 0.000340;
  distance_m = (float) pulse_length_us * 0.000170;

  Serial.print(millis() / 1000); Serial.print("\t");
  Serial.print(pulse_length_us); Serial.print("(us)\t");
  Serial.print(distance_m); Serial.print("(m)\n");
  delay(500);
}

/* notes:

   V_sound is temperature-dependant.  You could use an TMP36 to correct the distance readings
   temperature correction: http://hyperphysics.phy-astr.gsu.edu/hbase/Sound/souspe.html

   pulseIn() measures with a fidelity of 1us in the range [10us-~3minutes].
   What distance does 1us correspond to?
*/
/*
   Do we need to use pulseIn?  we could, in principle, enter into a for loop immediately after
   hitting trig pin.  We'd need to read echoPin and look for a Low->High transition and then a high->Low
   transition.  The elapsed time between these two transitions is what pulseIn returns.
   Why would this measurement be not as good? (note, code does not work)

// ask the sensor for a measurement
unsigned long t1, t2
long dt_us;
t1=0;
t2=0;
dt_us = -1;
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


old_read = digitalRead(echoPin);
while (dt_us < 0) {
  new_read = digitalRead(echoPin);
  if(!old_read && new_read) {
    // echopin rose!
    t1=micros();
  }
  if(old_read && !new_read) {
  // echopin fell!
    t2=micros();
  }
  dt_us = t2-t1;
  old_read = new_read;
}

*/
