/*
11 - Update the previous algorithm now making it possible to inform if the number is greater or less than the attempt.

Solutio:
*/
// Importing necessary libraries.
// Standard input and output.
#include <stdio.h>
// Importing time.
// We are going to use the time
// as our seed.
#include <time.h>
// Standard libraries.
#include <stdlib.h>

int main(void) {
  int num,num1,num2;

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
      printf("Nohh, the number is %d.\n", num);
    }
  }
}