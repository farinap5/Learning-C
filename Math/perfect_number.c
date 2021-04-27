#include <stdio.h>

int main() {
  // Numbe, count, divider
  int n, coun, div;
  // Sum of counter + sum
  int sum = 0;
  coun = 1;

  printf("Input a number: ");
  scanf("%d", &n);

  while (coun < n) {
    div = n % coun;
    if (div == 0) {
      //printf("%d\n",coun);
      sum += coun;
    }
    coun++;
  }
  if (sum == n) {
    printf("%d is a perfect number!\n",n);
  } else {
    printf("%d is not a perfect number!\n",n);
  }
  return 0;
}