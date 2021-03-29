/*
1 - Write a program that asks for an integer.
Display an error message if the number entered 
is between 15 and 25 or between 45 and 50.

Solution:
*/
#include <stdio.h>

// Main function
int main(void) {
  // Integer "n" number.
  int n;
  // Ask for a number.
  printf("Enter a number: ");
  // Store this number
  scanf("%d", &n);
  // Using logical and relational operators.
  if ((n > 15 && n < 25) || (n > 45 && n < 50)) {
    printf("ERROR!\n");
  }
  return 0;
}