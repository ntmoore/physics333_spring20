#define o_pin 10
void setup() {
  // put your setup code here, to run once:
  pinMode(o_pin, OUTPUT);
}

void loop() {

  /* as an example, the following function call will spit out 
   *  ~ 20x(3ms high, 7ms low) square waves on pin 10
   */
  ntm_pwm(200,300,10,10);

  delay(200);

  /* this would be very similar, but the on time would be 2.98ms */
  ntm_pwm(200,298,10,10);
    

}

void ntm_pwm(int duration, int power, int PWM_period, int output_pin) {
  /*
     int duration - how long will the signal be sent out? (ms, [1,1000])
     int power - what average power will be sent (out of 1000)
     int PWM_period - what granulatiry will you use in the power (us [5-20])
     int output_pin - what (Digital) pin are you broadcasting the signal on?
  */

  unsigned long time_0;
  time_0 = millis();

  while ((millis() - time_0) < duration ) {
    digitalWrite(output_pin, HIGH);
    //time the outputbit is high
    delayMicroseconds(power*PWM_period);
    
    digitalWrite(output_pin, LOW);
    // time the output bit is low
    delayMicroseconds((1000-power)*PWM_period);
  }
  return;
}
