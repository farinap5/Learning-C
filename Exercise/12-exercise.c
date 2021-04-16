/*
12 - Update the previous algorithm now with 3 attempts.

Solution:
*/
#include <stdio.h>
// Importing time.
// We are going to use the time
// as our seed.
#include <time.h>
// Standard libraries.
#include <stdlib.h>

int main(void) {
  int num,num1,num2,num3;

  // Generating randomized number.
  num = time(NULL);
  srand(num);
  num = (rand() % 10) + 1;

  printf("Provide a number: ");
  scanf("%d", &num1);
  
  if (num == num1){
    printf("Woow, you hit it!\n");
  } else {
    if (num > num1) {
      printf("Nope! the number is greater, try again: ");
    } else {
      printf("Nope! the number is smaller, try again: ");
    }
    scanf("%d", &num2);
    if (num == num2) {
      printf("Yay, now you hit it.\n");
    } else {
      if (num > num2) {
        printf("Noh, the number greater, try again: ");
      } else {
        printf("Noh, the number smaller, try again: ");
      }
      scanf("%d", &num3);
      if (num == num3) {
        printf("Now you hit it\n");
      } else {
        printf("No, the number is %d.\n", num);
      }
    }
  }
}