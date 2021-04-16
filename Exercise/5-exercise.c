/*
5 - make an algorithm that receives two numbers 
and shows in ascending order, or shows a message if they are equal.

Solution:
*/
#include <stdio.h>


// Main function
int main(){
  // Declare variable.
  int num1, num2;

  // Ask for two values and store.
  printf("Provide a number: ");
  scanf("%d", &num1);
  printf("Provide another number: ");
  scanf("%d", &num2);

  // Compare
  if (num1 < num2) {
    printf("%d is greater than %d.\n", num2,num1);
  } else{
    // If they are equal.
    if (num1 == num2) {
      printf("%d is equal to %d.\n", num1,num2);  
    } else {
      printf("%d is greater than %d.\n", num1,num2);
    }
  }
}