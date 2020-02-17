<h1>Notes on Teaching Examples</h1>

This file contains some short notes on the teaching examples in this repository.  For details, start with the index of a good book on C/C++ (eg [Kernighan and Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) ).

<h3>02_17-array1.c	</h3>

This code introduces arrays.  Note the very strange (and powerful, and dangerous) thing C allows you to do - you can read outside of the array bounds!  Also note that arrays are (sometimes) initialized to 0.  Don't rely on this being true in all cases.

<h3>02_17-array2.c	</h3>

You can also write OUTSIDE of the array bounds.  Note again that this is poison!  What memory are you over-writing?  This is how computer viruses can operate.  C does not restrict you to only work within the bounds of an array.

<h3>02_17-array3.c</h3>

This example shows how you can pass array data into a function (this one computes the dot product of a pair of vectors). The passing in C is typically "by reference" - ie, you tell the function where the data lives via a "pointer" and the function works on it.  Some languages also pass "by value" in which the data is copied over into a new memory location by the program.  The difference is something like driving a dumptruck of gravel over to yuor neighbor's house vs telling the dumptruck where to pick up the gravel.  

<h3>02_17-array4.c </h3>

You can also pass data back from a function via the pass-by-reference mechanism.  In this program, a function is fed two vectors and then returns their cross product as a function argument.

<h3>02_17-music_player.c </h3>

This program plays music, sort-of.  Instead of pulsing out sine-wave based tones, the output pin is written high-low at a frequency that corresponds to a given musical note.  You could say some complicated things about how a square wave is composed of a Fourier series of harmonics, but for now it's enough to note that the music sounds pretty harsh. 
The code uses a lookup function to map notes, eg A4, to periods.  This is done with the character comparison function strcmp(), which returns 0 if the two arguments are equal.
The next step would be to feed the code a string of notes and durations (ie, a song), but what would be the best data structure to use?  
