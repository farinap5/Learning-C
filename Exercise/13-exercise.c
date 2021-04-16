/*
13 - Draw two numbers from 1 to 5 and ask the user to hit the two numbers,not in the same order.

Solution:
Increment operator will be used.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int num0,num1,hit0,hit1;
  int i = 0;

  // Generating random number
  // for the first variable.
  num0 = time(NULL);
  srand(num0);
  num0 = (rand() % 5) + 1;

  // The last variables has some part done,
  // so I will take to make esier.
  num1 = (rand() % 5) + 1;
  // Print to check if is everything going well.
  printf("%d\n %d\n", num0, num1);

  printf("Provide a number in range 1-5: ");
  scanf("%d", &hit0);
  printf("Provide a number in range 1-5: ");
  scanf("%d", &hit1);

  if (num0 == hit0 || num0 == hit1) {
    i++;// i = i + 1
  }

  if (num1 == hit0 || num1 == hit1) {
    i++;
  }

  printf("%d was number(s) hitted.\n",i);

  return 0;
}