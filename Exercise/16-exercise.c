/*
16 - Write a program that displays any complete multiplication tables. The program should ask the user which multiplication table he wants to view, which he will answer by typing a number from 1 to 10.

Solution:
*/

#include <stdio.h>

int main(void) {
  // Declaring variables.
  // "t" will be the chosen number.
  // "c" will multiply "t".
  int t,c;

  // Ask for a number and store in "t".
  printf("Intput a number in range 1-10: ");
  scanf("%d", &t);
  // "c" receives 1.
  c = 1;

  // While "c" is smaller than 10.
  while (c <= 10) {
    // print -> "t" x "c" = t*c
    printf("%d x %d = %d\n",t,c,t*c);
    // Use increment operator
    c++; // c = c + 1
  }

  return 0;
}