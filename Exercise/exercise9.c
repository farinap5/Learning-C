/*
9 - Remake the previous exercise now showing right triangle.

Solution:
*/


#include <stdio.h>

int main(void) {
  int num1,num2,num3;
  int num1q, num2q, num3q;

  printf("Input a number: ");
  scanf("%d", &num1);
  printf("Input a number: ");
  scanf("%d", &num2);
  printf("Input a number: ");
  scanf("%d", &num3);

  num1q = (num1 * num1);
  num2q = (num2 * num2);
  num3q = (num3 * num3);

  if (num1 > num2 + num3 || num2 > num1 + num3 || num3 > num1 + num2) {
    printf("Given numbers can not be part of a triangle!\n");
  } else {
    if (num1 == num2 && num1 == num3) {
      printf("Equilateral Triangle!\n");
    } else{
      if (num1q + num2q == num3q || num3q + num2q == num1q || num1q + num3q == num2q) {
        printf("Right Triangle!\n");
      } else {
        if (num1 == num2 || num1 == num3 || num2 == num3) {
          printf("Isosceles Triangle!\n");
        }
        if (num1 != num2 && num1 != num3 && num2 != num3) {
          printf("Escalene Triangle!\n");
        }
      }
    }
  }
  return 0;
}