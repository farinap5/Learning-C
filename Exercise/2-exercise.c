/*
2 - Make an algorithm that receives two numbers 
and shows in ascending order.

Solution:
*/

#include <stdio.h>

// Main function
int main(void) {
  // Declaring the variables that receive the values.
  int num1, num2;

  // Ask for the number and store the given velue.
  printf("Provide a number: ");
  scanf("%d", &num1);
  printf("Provide another number: ");
  scanf("%d", &num2);

  // Comparing both using relational operators.
  if (num1 < num2) {
    printf("%d is greater than %d\n", num2,num1);
  } else{
    printf("%d is greater than %d\n", num1,num2);
  }
  
  return 0;
}