/*
A simple implementation of generating random numbers.
Having the current time as seed.
*/

// Importing necessary libraries.
// Standard imput and output.
#include <stdio.h>
// Importing time.
#include <time.h>
// Standard libraries.
#include <stdlib.h>

// Main function
int main(void) {
  // Taking time and storing in the newly created variable "a".
  int a = time(NULL);
  
  // Random number generator with given integer number.
  // This given number is the current time.
  srand(a);
  // The random number is stored in the newly created variable "b".
  int b = rand();
  // Output the random number.
  printf("%d\n",b);
  return 0;
}