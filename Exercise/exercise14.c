/*
14 - Draw two numbers from 1 to 10 and inform how many of these numbers are between 3 and 7.

Solution:
Increment operator will be used.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int num0,num1;
  int i = 0;

  // Generating random number
  // for the first variable.
  num0 = time(NULL);
  srand(num0);
  num0 = (rand() % 10) + 1;

  // The last variables has some part done,
  // so I will take to make esier.
  num1 = (rand() % 10) + 1;

  if (num0 > 3 && num0 < 7) {
    i++;// i = i + 1
  }
  if (num1 > 3 && num1 < 7) {
    i++;
  }
  printf("%d number(s) in the range 3-7!\n",i);

  return 0;
}
