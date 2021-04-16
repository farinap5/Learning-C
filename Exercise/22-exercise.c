/*
22 - Ask the user to enter a number between 10 and 20. If an invalid number is entered, ask again until the user enters a correct number.

Solution:
*/

#include <stdio.h>

int main(void) {
  // "n" number
  int n;

  // while number is out of range.
  while (n < 10 || n > 20) {
    // ask for a number.
    printf("Input a number in range of 10-20: ");
    // and store the number in "n".
    scanf("%d",&n);
  }
  // if "n" is in the range, breake the "while". 
  printf("OK! the number %d is in the range.\n",n);
  return 0;
}