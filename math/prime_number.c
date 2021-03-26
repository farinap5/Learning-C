/*
This program will check if the number contained in the 
variable num is a prime number.
If the number can be divided, the scenario will be shown.
*/
#include <stdio.h>

// Main function
int main(void) {
  int num = 999983;
  /* 
  The value of x will start as 2.
  The variable num will be divided by x.
  If num can not be divided, 1 will be added in x.
  The count will be made again, num will be divided by x, 
  if not possible, 1 will be added in x again.
  If the variable x reaches the value of num, 
  num can be considered a prime number.
  */
  for (int x = 2; x <= num; x++) {
    //If num divided by x is equal to zero,
    //and num is different of x.
    //so it is not a prime number.
    if (num % x == 0 && num != x) {
      printf("%d / %d", num,x);
      break;
    }
    if (num == x) {
      printf("%d id a prime number\n", num);
    }
  }
  return 0;
}
