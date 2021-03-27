// Increment operator examples.
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
  a = a + 1;
  
  // The second type facilitate the syntax.
  // b /= 1;
  // b *= 1;
  // b -= 1;
  b += 3; // c = c + 3 <-> c = 8
  
  // The third type only serves to add the 
  // value 1 to the variable.
  // c = c + 1
  c++; // = 6  

  // Output the final values of each variable.
  printf("Value of a = %d\nValue of b = %d\nValue of c = %d\n", a,b,c);
  return 0;
}