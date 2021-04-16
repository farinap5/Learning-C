/*
15 - Zeca will use a computer to control the daily income of his work as fisherman.
Each time he brings a fish weight greater than that established by the fishing regulation (50kg) he must
pay a fine of $4.00 for each kilogram. Zeca needs an algorithm to help him calculating if there is any 
excess and how much is this excess.


Solution:
*/
#include <stdio.h>

// Main function
int main(void) {
  // Variable fish weight.
  int pp;
  // Variable of subtraction and multiplication.
  int sub, mult;

  // Ask for the weight of the fish
  printf("Insert the weight of the fish: ");
  // store the value
  scanf("%d", &pp);

  // Compare the weight with the established.
  if (pp > 50) {
    // If the fish is heavier than 50kg.
    // Finding out what the fine will be.
    sub = pp - 50;
    printf("The weight of the fish exceeds by %dkg.\n", sub);
    mult = sub * 4;
    printf("The amount of the fine will be $%d.\n",mult);
  } else {
    printf("The weight of the fish is within the regulation.\n");
  }
  return 0;
}