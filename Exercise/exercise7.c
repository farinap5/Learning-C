/*
7 - Make an algorithm that receives a number and shows a message 
if this number is greater than 80, less than 25 or equal to 40.

Solution:
*/

#include <stdio.h>

// Main function
int main(void) {
  // Variable n = number
  int n;

  // Output massage asking for a number.
  printf("Enter a number: ");
  // Store given number.
  scanf("%d", &n);

  // Using logical and relational operators to compare.
  // -----25-------40-------80-----
  // true <|false|true|false|> true
  if (n > 80 || n < 25 || n == 40) {
    printf("OK\n");
  }

  return 0;
}