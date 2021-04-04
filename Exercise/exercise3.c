/*
3 - Make an algorithm that asks for a number 
and shows if the number is pair or inpair.

Solution:
*/

#include <stdio.h>

// Main function
int main(void) {
  // Variable number and div.
  int num, div;

  // Ask for a number and store it.
  printf("Provide a number: ");
  scanf("%d", &num);

  // Divide the number by 2, if it is pair the rest will be 0.
  div = num % 2;


  // Compare the rest.
  if (div == 0) {
    printf("The number %d is pair.\n", num);
  } else {
    printf("The number %d is inpair.\n",num);
  }
  return 0;
}