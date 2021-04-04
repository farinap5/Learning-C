/*
4 - Create a program that receives a number 
and inform if it is a multiple of 10.

Solution:
*/

#include <stdio.h>

// Main function
int main(void) {
  // Declare number varable and div.
  int num, div;

  printf("Provide a number: ");
  scanf("%d", &num);

  // Divide the number by 10, if the rest is equal to 0,
  //than the number is multiple of 10.
  div = num % 10;

  // Compare the rest.
  if (div == 0) {
    printf("the number %d is multiple of 10.\n", num);
  } else {
    printf("the number %d is not multiple of 10.\n", num);
  }

  return 0;
}