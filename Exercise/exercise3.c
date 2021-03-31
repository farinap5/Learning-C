/*
Increment the previous exercise, in case the measures 
form a valid triangle, inform which type of triangle they form: 
equilateral, isosceles or scalene.
*/
#include <stdio.h>

// Main function
int main(void) {
  // First number
  int a;
  // Second number
  int b;
  // Third number
  int c;

  printf("Enter a number: ");
  scanf("%d",&a);
  printf("Enter a number: ");
  scanf("%d",&b);
  printf("Enter a number: ");
  scanf("%d",&c);

  // Try to find out if given number can be part of a triangle.
  if (a > b + c || b > a + c || c > a + b) {
    printf("Given numbers can't be a part of a triangle!\n");
  } else {
    // If yes we can figure out the type looking at patterns.
    // If all sides are equal.
    if (a == b && a == c){
      printf("Equilateral Triangle!\n");
    } else {
      // If Two sides are equal.
      if (a == b || a == c || c == b) {
        printf("Isosceles Triangle\n");
      // Or if no sides are equal.
      } else{
        printf("Escalene Triangle\n");
      }
    }
  }
}