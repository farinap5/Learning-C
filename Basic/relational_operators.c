/*
Relational Operators are used two compare to values or 
two variables.

 > | X >  Y | X is greater than Y
>= | X >= Y | X is greater or equal to Y
 < | X <  Y | X is smaller than y
<= | X <= Y | X is smaller or equal to Y
== | X == Y | X is equal to Y
!= | X != Y | X is different from Y

*/

#include <stdio.h>

int main(void) {
    int number = 5;

    if (number == 5) {
        printf("The number %d is equal to 5.\n",number);
    }
    if (number > 4) {
        printf("The number %d is greater than 4.\n",number);
    }
    if (number != 8) {
        printf("The number %d is different from 8.\n",number);
    }
    return 0;
}