#include <stdio.h>
// Tibrary to work with boolean
#include <stdbool.h>

// Main function
int main(void) {
    // Declare boolean variable
    bool boo;
    // Declare integer variable
    int num;

    // Prompt a message asking a number
    printf("Enter a number: ");
    // Store the number
    scanf("%d", &num);
    
    // If the number is pair, then it is true
    if (num%2 == 0) {
        boo = true;
    // If the number is odd, then it's false
    } else {
        boo = false;
    }


    if (boo == false) {
        printf("False condition!\n");
    } else {
        printf("True condition!\n");
    }
    return 0;
}