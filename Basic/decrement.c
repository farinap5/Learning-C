// Decrement operator examples.
#include<stdio.h>

// Main  function.
int main(void) {
  // Declaring variables
  // Integer values.
  int a, b, c;

  // Store data.
  a = 5; 
  b = 5;
  c = 5;

  // The first operator is simple but not
  // the easier to be used.
  a = a - 1;
  
  // This is very similar to the example of incremetation.
  b -= 3; // c = c - 3 <-> c = 2
  
  // The third example is only used to subtract a value.
  // c = c - 1
  c--; // = 4  

  // Output the final values of each variable.
  printf("Value of a = %d\nValue of b = %d\nValue of c = %d\n", a,b,c);
  return 0;
}