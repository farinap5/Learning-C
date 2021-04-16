/*
20 - Write a program that asks for 10 numbers and at the end displays the sum of all of them.

Solution:
*/

int main(void) {
  // "n" number inputed
  // "c" counter
  // "nn" nnumber + number inputed.
  int n,c, nn;


  c = 1;
  nn = 0;

  while (c <= 10) {
    printf("Input a number: ");
    scanf("%d", &n);

    // inputed number + previously inputed numbers
    nn = nn + n;
    c++; // c = c + 1
  };
  // display the sum.
  printf("%d\n",nn);
  return 0;
}