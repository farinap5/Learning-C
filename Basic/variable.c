#include <stdio.h>

// main function
int main(void) {
    // Declaring variables
    int intNumber;
    float floatNumber;
    char strData[50] = "Hello World";  

    // Assigning values
    // strData has already been signed
    intNumber = 10;
    floatNumber = 5.3;

    // Show the value of the variables
    printf("%d\n", intNumber);
    printf("%f\n",floatNumber);
    printf("%s\n", strData);
    return 0;
}