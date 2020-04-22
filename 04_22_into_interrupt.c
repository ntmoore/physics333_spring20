/*  Basic hardware interrupts on Arduino Uno
     references:
     https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt
     http://gammon.com.au/interrupts
*/

// On which pin are we listening for an interrupt?
// on Uno, 2 or 3 are available
#define INTERRUPT_PIN 2

// store the times at which the interrupt is triggered
// varaibles in the ISR should be global (outside of setup/loop)
// and volatile
#define N 20
volatile long times[N];
volatile int i = 0;
volatile long time_of_last_interrupt_call=0;
  
// LED
#define ledPin 13
volatile byte ledstate = 0;

unsigned long t0;

void setup() {
  pinMode(ledPin, OUTPUT);
  //pinMode(interruptPin,INPUT_PULLUP);
  attachInterrupt(
    digitalPinToInterrupt(INTERRUPT_PIN), // which pin?
    catch_change,   //ISR
    CHANGE  // mode
    //    RISING  // or, use this to catch just a rising clock
  );
  Serial.begin(9600);
  t0 = millis();
}

void loop() {

  digitalWrite(ledPin, ledstate);

  int j;
  // only print out the interrupt
  if ((millis() - t0) > 3000) {
    Serial.print(i);
    Serial.println(" interrupts seen in last 3s.  They ocurred at:");
    for (j = 0; j < i; j++) {
      Serial.println(times[j]);
    }
    i = 0;
    t0 = millis();
  }

}

// this is my interrupt service routine (ISR)
void catch_change() {
  if (i < N && (micros()-time_of_last_interrupt_call)> 100000) {  
    time_of_last_interrupt_call = micros();
    times[i] = time_of_last_interrupt_call;
    i++;
    ledstate = !ledstate;
  }
}
