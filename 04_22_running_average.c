/* 
this stores the last 10 analog reads and computes a running average.  Might be useful for Lab 4
*/


int stored_T[10];
int i = 0;

void setup() {
  Serial.begin(9600);

  // fill the array with data
  for (i = 0; i < 10; i++) {
    stored_T[i] = analogRead(A0);
  }
  i = 0;
}

void loop() {
  int t = analogRead(A0);
  stored_T[i] = t;
  int last_i = i - 1;
  if (last_i < 0) {
    last_i = 9;
  }
  int change_since_last = stored_T[i] - stored_T[i - 1];
  Serial.print("values: ");
  for(int j=0;j<10;j++) { Serial.print(stored_T[j]); Serial.print(" "); }
  Serial.print("\tchange: ");
  Serial.print(change_since_last);
  i++;
  if (i == 10) {
    i = 0;
  }

  long sum = 0;
  int j;
  for (j = 0; j < 10; j++) {
    sum += stored_T[j];
  }
  float avg_t = sum / 10;
  Serial.print("\t avg:  ");
  Serial.println(avg_t);
  
  delay(1000);
}

/* output looks like: 
values: 504 450 419 505 505 504 504 504 504 504 	change: -31	 avg:  490.00
values: 504 450 419 401 505 504 504 504 504 504 	change: -18	 avg:  479.00
values: 504 450 419 401 392 504 504 504 504 504 	change: -9	 avg:  468.00
values: 504 450 419 401 392 387 504 504 504 504 	change: -5	 avg:  456.00
values: 504 450 419 401 392 387 383 504 504 504 	change: -4	 avg:  444.00
values: 504 450 419 401 392 387 383 382 504 504 	change: -1	 avg:  432.00
values: 504 450 419 401 392 387 383 382 381 504 	change: -1	 avg:  420.00
values: 504 450 419 401 392 387 383 382 381 387 	change: 6	 avg:  408.00
values: 382 450 419 401 392 387 383 382 381 387 	change: 382	 avg:  396.00
values: 382 379 419 401 392 387 383 382 381 387 	change: -3	 avg:  389.00
values: 382 379 377 401 392 387 383 382 381 387 	change: -2	 avg:  385.00
values: 382 379 377 377 392 387 383 382 381 387 	change: 0	 avg:  382.00
values: 382 379 377 377 377 387 383 382 381 387 	change: 0	 avg:  381.00
*/
