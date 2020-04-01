/*
  ntm_morse_comm
  Nathan Moore
  www.github.com/ntmoore
  modified 2016 Feb 9
  Using a function to hide the morse code bit banging
    this example sends morse code and a clock to synchronize
  This parameter defines the length of a "dot" in Morse
  all other times are based on this unit, eg
    dash is 3d
    spacing between dot/dash is 1d
    spacing between letters is 3d
    spacing between words is 7d
   all according to wikipedia,
  https://en.wikipedia.org/wiki/Morse_code
*/

/*
  modified 2018-3-19
  Ben Andrews
  www.github.com/bandrewss
  -moved word space into switch statement
  -moved print_letter_space() function call into print_morse()
  -changed for to while to traverse target string
 */
int d = 100; // dot length in ms

// these are the pins the signal is sent out on
int signal_pin = 13;
int clk_pin = 12;

void setup() {

  // initialize digital pin 13 as an output.
  pinMode(signal_pin, OUTPUT);
  pinMode(clk_pin, OUTPUT);

  Serial.begin(9600);

  //enforcing even d for the sake of symmetric clk signal
  if ((d % 2) == 1) {
    d = d + 1;
  }
}

void loop() {

  //char message1[] = "sos-hello-world-sos";
  char message1[] = {"The-quick-brown-fox-jumps-over-the-lazy-dog-0123456789"};

  int i = 0;

  // iterate over message until null terminator
  while(message1[i] != '\0') {
      print_morse(clk_pin,  signal_pin, d, message1[i]);
      Serial.println(message1[i]);
      i++;
  }

  print_morse(clk_pin,  signal_pin, d, '-');
  print_morse(clk_pin,  signal_pin, d, '-');
  print_morse(clk_pin,  signal_pin, d, '-');
  print_morse(clk_pin,  signal_pin, d, '-');
  
  Serial.println("");

}


// print out the space between letters
void print_letter_space(int clk, int out_pin, int d) {

  // flashing out clock for 3d,
  // implicitly, signal is held low, but let's make sure
  digitalWrite(out_pin, LOW);
  // 0
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // 1
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // 2
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // 3
  return;
}

void do_one_clock_pulse(int clk, int d) {
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // -or-
  //  delay(d); // dot without a clock
  return;
}

void do_three_clock_pulses(int clk, int d) {
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // 1
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // 2
  digitalWrite(clk, HIGH);
  delay(d / 2);
  digitalWrite(clk, LOW);
  delay(d / 2);
  // 3
  // equivalent to
  // delay (3 * d) if there were no clock
  return ;
}


// d - dot length (ms) (dash is 3d, clock runs at d)
// c - character to be flashed via morse code
// outpin - pin that the morse is written to
// clk_pin - pin that the synchronizing clock signal is written to
int print_morse(int clk_pin, int out_pin, int d, char c) {
  int success = 1;

  switch (c) {

    case 'a': case 'A': //  .-
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d);  // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      // equivalent to
      //do_one_clock_pulse(clk_pin, d);
      //do_one_clock_pulse(clk_pin, d);
      //do_one_clock_pulse(clk_pin, d);
      digitalWrite(out_pin, LOW);
      break;

    case 'b': case 'B': // -...
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'c': case 'C': // -.-.
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'd': case 'D': // -..
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'e': case 'E': // .
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'f': case 'F': // ..-.
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'g': case 'G': //--.
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'h': case 'H': // ....
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'i': case 'I': //..
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'j': case 'J': //.---
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'k': case 'K': //-.-
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d);   // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'l': case 'L': // .-..
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'm': case 'M': // --
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'n': case 'N': //  -.
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'o': case 'O': // ---
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'p': case 'P': // .--.
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case 'q': case 'Q': // --.-
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'r': case 'R': // .-.
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case 's': case 'S': // ...
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case 't': case 'T':// -
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'u': case 'U': //..-
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'v': case 'V': // ...-
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'w': case 'W': //.--
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'x': case 'X': //-..-
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'y': case 'Y': // -.--
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case 'z': case 'Z': // --..
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case '1': // .----
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case '2': // ..---
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case '3': // ...--
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case '4': // ....-
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case '5': // .....
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case '6': // -....
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case '7': // --...
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case '8': // ---..
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case '9': // ----.
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_one_clock_pulse(clk_pin, d); // dot
      digitalWrite(out_pin, LOW);
      break;

    case '0': // -----
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      do_one_clock_pulse(clk_pin, d); // space
      digitalWrite(out_pin, HIGH);
      do_three_clock_pulses(clk_pin, d);   // dash
      digitalWrite(out_pin, LOW);
      break;

    case '-': case ' ':
      // flashing out clock signal for 7d
      // implicitly, signal is held low, but let's make sure
      digitalWrite(out_pin, LOW);
      /* commenting out the first 3 cycles because every letter
          is printed with a trailing letter space of 3d
        // 0
        digitalWrite(clk_pin, HIGH);
        delay(d / 2);
        digitalWrite(clk_pin, LOW);
        delay(d / 2);
        // 1
        digitalWrite(clk_pin, HIGH);
        delay(d / 2);
        digitalWrite(clk_pin, LOW);
        delay(d / 2);
        // 2
        digitalWrite(clk_pin, HIGH);
        delay(d / 2);
        digitalWrite(clk_pin, LOW);
        delay(d / 2);
      */

      /* the next three are commented out because a letter space 
           gets printed out after the word space
      // 3
      digitalWrite(clk_pin, HIGH);
      delay(d / 2);
      digitalWrite(clk_pin, LOW);
      delay(d / 2);
      // 4
      digitalWrite(clk_pin, HIGH);
      delay(d / 2);
      digitalWrite(clk_pin, LOW);
      delay(d / 2);
      // 5
      digitalWrite(clk_pin, HIGH);
      delay(d / 2);
      digitalWrite(clk_pin, LOW);
      delay(d / 2);
      */
      
      // 6
      digitalWrite(clk_pin, HIGH);
      delay(d / 2);
      digitalWrite(clk_pin, LOW);
      delay(d / 2);
      // 7
      break;
      
    
    default:
      // this is an error state
      Serial.print("!!!!!\n!!!!!\n!!!!!\n");
      Serial.println("I don't know how to print this character:");
      Serial.println(c);
      Serial.println("!!!!!\n!!!!!\n!!!!!\n");
      success = 0;
      break;
  }

  print_letter_space(clk_pin, signal_pin, d);

  return success;
}
