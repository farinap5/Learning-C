/*
Fibonacci
*/

#include <stdio.h>

int main(void) {
  int x, y, z;

  while (1) {
    x = 0;
    y = 1;

    do {
      printf("%d\n",x);

      z = x + y;
      x = y;
      y = z;
    } while (x < 145);
  }
  return 0;
}
/*
Fibonacci Function
#####
X Y Z-Declared variables.
0 1 0-Given values.
------Start loop
0 1 1-Z = X + Y = 0 + 1 
1 1 1-X = Y = 1
1 1 1-Y = Z = 1
-----New loop
1 1 2
1 1 2
1 2 2
-----New loop
1 2 3
2 2 3
2 3 3
-----
*/