/*
17 - Write a program that displays the square of all numbers from 1 to 20.

Ex:
1 - 1
2 - 4
3 - 9
4 - 16
------
20 - 400

Solution:
*/

#include <stdio.h>

// Main function
int main(void) {
  int n = 1;

  // While n smaller tham 20
  while (n <= 20) {
    // n - n*n
    // 5 - 25
    printf("%d - %d\n",n,n*n);
    // Use increment operator
    n++;
  }
  return 0;
}