/*
19 - Write a program that displays the sum of the numbers from 1 to 100.

Solution:
*/

#include <stdio.h>

int main(void) {
  // Counter and Number
  int c,n;

  // counter starts being 1.
  c = 1;
  // Number starts being 0;
  n = 0;

  // while counter is smaller than 100.
  while (c <= 100) {
    // number = bumber + counter.
    n = n + c;
    // counter = counter + 1.
    c++;
  }
  // when finished, output the value.
  printf("%d\n",n);
  return 0;
}
/*
c  n
1  0
----
1  1 n = n + c | 0 = 0 + 1
2  1 c++       | 1 = 1 + 1
----
2  3 n = n + c | 3 = 1 + 2
3  3 c++       | 2 = 2 + 1
*/