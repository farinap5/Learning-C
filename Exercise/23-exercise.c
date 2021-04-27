/*
23 - Write a program that asks for the code and the height of 5 athletes. At the end of the data entry, propt the height and code of the tallest athlete.


Solution:
*/

#include <stdio.h>

int main(void) {
  int count = 1;

  // Athlete Code
  int cod = 0;
  // Athlete Height
  int num = 0;

  // New Athlete Code
  int codn;
  // New Athlete Height
  int numn;

  printf("-----------\n");
  while (count <= 5) {
    printf("Athlete: ");
    scanf("%d", &codn);
    printf("Height: ");
    scanf("%d", &numn);
    printf("-----------\n");

    // The tallest athlete will remain in the variable.
    if (numn > num) {
      num = numn;
      cod = codn;
    }
    count++;
  }

  printf("The athlete %d is the tallest: %d cm\n",cod,num);
  return 0;
}