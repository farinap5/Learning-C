/*
18 - Write a program that asks the user for 5 numbers, and for each number entered, informs if it is pair or inpair.

Solution:
*/

#include <stdio.h>

// Main function
int main(void) {
  // Declaring variables
  // "n" number chosen by the user.
  // "c" counter
  // "d" divider
  int n,c,d;

  // counter starts being 1.
  c = 1;

  // while counter is smaller than 5.
  while (c <= 5) {
    // ask for a number.
    printf("Input a number: ");
    // store this number.
    scanf("%d", &n);

    // divide by 2 and take the rest
    d = n % 2;
    // if rest is equal to 0
    // the number is pair
    if (d == 0) {
      printf("%d is pair.\n",n);
    } else {
      printf("%d is inpair.\n",n);
    }
    // increment operator.
    c++; // c = c + 1
  }
  return 0;
}