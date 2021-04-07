/*
Logical operators are used when we need to compare two or more conditions
inside the same instruction "if" and the result of all conditions must be
true or false.

AND = &&    3 > 2 && 3 < 4 = true
OR  = ||    3 > 2 || 3 > 4 = true because one condition would return true
*/

// Import standard input and output. 
#include <stdio.h>

// Main function
int main() {
    int num = 5;

    printf("Number = %d", num);

    // If our number is greater than 3 and smaller than 10, 
    // so the condition returns true and the message will appear.
    if (num > 3 && num < 10) {
        printf("%d is greater than 3 and smaller than 10\n",num);
    } else {
        printf("!!ERROR!!\n");
    }

    // If our number is greater than 10 or greater than 3, 
    // so the condition returns true and the message will appear.
    if (num > 10 || num > 3) {
        printf("%d is greater than 10 or greater than 3\n",num);
    } else {
        printf("!!ERROR!!\n");
    }
    
    return 0;
}

