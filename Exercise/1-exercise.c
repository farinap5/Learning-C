/*
1 - Make an algorithm that receives a number and shows 
a message if that number is greater than 10.

Solution:
*/

#include <stdio.h>

// Main function
int main(void){
  // Variable number
  int num;
  // Variable to compare
  int com;

  com = 10;

  // Ask for the number.
  printf("Insert a number: ");
  // Store the number.
  scanf("%d", &num);

  // Comparing using relational operators.
  if (num > com) {
    printf("The number %d is greater than %d!\n",num,com);
  }
  return 0;
}