#define o_pin 10
// uncomment the next line if you want verbose warnings
#define WARNINGS
void setup() {
  pinMode(o_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  pwm_100(200, 99, 10, 10);

  pwm_100(200, 98, 10, 10);

}

void pwm_100(int duration_ms, int power, int PWM_period_us, int output_pin) {
  /*
     pwm algorithm that runs with power levels 0-100% (not 0-1000 as previous versions)
     int duration - how long will the signal be sent out? (ms, [1,???])
     int power - what average power will be sent (out of 100)
     int PWM_period_us - what granulatiry will you use in the power (us [5-20])
     int output_pin - what (Digital) pin are you broadcasting the signal on?
  */

  unsigned long time_0;
  time_0 = millis();

#ifdef WARNINGS
  if (power > 100 || power < 0) {
    Serial.print("bad power specification, power = ");
    Serial.println(power);
  }
  if (PWM_period_us <= 5) {
    Serial.print("code is not reliable: you're useing a very short PWM_period_us = "); Serial.println(PWM_period_us);
  }
  if ((duration_ms * 1000) % (100 * PWM_period_us) != 0) {
    char msg[100];
    sprintf(msg, "mismatch between duration_ms = %d, PWM_period_us=%d, and the 100 cycle fidelity.\t%d \n ",
            duration_ms, PWM_period_us, (duration_ms * 1000) % (100 * PWM_period_us) );
    Serial.print(msg);
  }
#endif

  while ((millis() - time_0) < duration_ms ) {
    digitalWrite(output_pin, HIGH);
    delayMicroseconds(power * PWM_period_us);

    digitalWrite(output_pin, LOW);
    delayMicroseconds((100 - power)*PWM_period_us);
  }
  return;
}
