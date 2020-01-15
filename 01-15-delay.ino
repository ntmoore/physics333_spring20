/*

*/

#define LED_pin 13
int dt; // why can't you use "delay" as a variable name?

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  dt = 200;
  digitalWrite(LED_pin, HIGH);
  delay(dt);
  digitalWrite(LED_pin, LOW);
  delay(dt);

  dt = dt * 5;
  digitalWrite(LED_pin, HIGH);
  delay(dt);
  digitalWrite(LED_pin, LOW);
  delay(dt);

}
