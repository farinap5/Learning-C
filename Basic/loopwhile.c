// A simple example of loop using while.

#include <stdio.h>

// Main function
int main() {
    // Declare int variable.
    int i = 1;
    // This function will run forever, until the program is turned off.
    while (1) {
        // i = i + 1
        i++;
        // Output the current value of "i".
        printf("%d\n", i);
        // If the value of variable "i" is equal to 10, break this loop.
        if (i == 10){
          break;
        }
    }
    return 0;
}
