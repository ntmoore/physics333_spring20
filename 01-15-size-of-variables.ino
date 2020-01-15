
//Grabbing types from https://www.arduino.cc/reference/en/
int i = 1;
long l = 2;
short s = 2;
char c = 'f'; // note, "f" doesn't work
float f = acos(-1.0); // this is PI to machine precision
double d = acos(-1.0);
byte by = 2;
bool boo = 2;

void setup() {
  // start up the serial (USB) connection
  Serial.begin(9600);
}

void loop() {

  // for more on serial.print, see https://www.arduino.cc/reference/en/language/functions/communication/serial/print/
  if (i < 2) {
    Serial.print(" the value of i is ");
    Serial.println(i);
    Serial.print("The size (bytes) of i is ");
    Serial.println(sizeof(i));

    Serial.print(" the value of s is ");
    Serial.println(s);
    Serial.print("The size (bytes) of s is ");
    Serial.println(sizeof(s));

    Serial.print(" the value of l is ");
    Serial.println(l);
    Serial.print("The size (bytes) of l is ");
    Serial.println(sizeof(l));
    i = i + 1;


  }
}
