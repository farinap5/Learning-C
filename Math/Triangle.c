/*
This program will ask for three numbers, 
after that it will tell you if those three 
numbers may or may not form a triangle.
*/
#include <stdio.h>

// Main fnction
int main(void) {
  // Variables to receive the numbers.
  int a, b, c;
  
  // Ask for a number three times.
  printf("Enter a number: ");
  // Store the number.
  scanf("%d",&a);
  printf("Enter a number: ");
  scanf("%d",&b);
  printf("Enter a number: ");
  scanf("%d",&c);

  // Using logical and relational operators to compare.
  // The amount of the two sides can not be smaller than the third side.
  if (a > b + c || b > a + c || c > a + b) {
    // However if one side is larger than the sum of the other two.
    printf("Given numbers can't be a part of a triangle!\n");
  } else {
      printf("The given numbers can be part of a triangle!\n");
  }

  return 0;
}