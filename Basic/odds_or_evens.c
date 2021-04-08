// odds or evens

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int side, num, sort, plus;

  sort = time(NULL);
  srand(sort);
  sort = rand() % 5 +1;
  //printf("%d\n", sort);
  printf("Hey, let's play odds or evens!\n");
  printf("Chose your side:\n[1]-Pair [2]-Inpair: ");
  scanf("%d", &side);

  

  if (side == 1){
    printf("OK, I'm going to be Inpair side.\n");
    printf("Give a number in range 1-5: ");
    scanf("%d", &num);

    plus = num + sort;
    plus = plus % 2;

    if (plus == 0) {
      printf("Woooww, You won!\n");
    } else {
      printf("I won ;)\n");
    }
  
  } else {
    printf("OK, I'm going to be Pair side.\n");
    printf("Give a number in range 1-5: ");
    scanf("%d", &num);

    plus = num + sort;
    plus = plus % 2;

    if (plus != 0) {
      printf("Woooww, You won!\n");
    } else {
      printf("I won ;)\n");
    }
  }
  return 0;
}