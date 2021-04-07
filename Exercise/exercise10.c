/*
10 - Make an algorithm that draws a number from one to ten and gives the user two chances to hit it.

Solution:
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

// Main function
int main(void) {
  int num,num1,num2;

  // Generating randomized number.
  num = time(NULL);
  srand(num);
  num = (rand() % 10) + 1;

  printf("Provide a number: ");
  scanf("%d", &num1);
  
  if (num == num1) {
    printf("Woow, you hit it!!\n");
  } else {
    // Second chance
    printf("Nope, You have another chance: ");
    scanf("%d", &num2);
    if (num == num2) {
      printf("Now you hit it\n");
    } else {
      printf("Nay!\n");
    }
  }
}