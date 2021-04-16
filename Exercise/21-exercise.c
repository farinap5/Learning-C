/*
21 - Write a program that prompts the user for a number, and then displays all of its divisors.

12
6
4
3
2
1

Solution:
*/

#include <stdio.h>
// main function
int main(void) {
  // chosen number
  // c counter
  // d divided 
  int n,c,d;

  // c starts as 1
  c = 1;

  // ask for a number and store the number. 
  printf("Input a number: ");
  scanf("%d",&n);

  // while counter is smaller than chosen number.
  while (c <= n) {
    // divided = chosen number / counter
    d = n % c;
    // if the rest is equal to zero,
    // the chosen number can be divided by the current counter.
    if (d == 0 && c != n) {
      // show the current counter
      printf("%d\n",c);
    }
    // increment operator.
    c++;
  }
  return 0;
}