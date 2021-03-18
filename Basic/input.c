#include <stdio.h>

// Main function 
int main(void) {
    // Declare username variable as string
    char name[50];

    // Prompt user to input username
    printf("Enter your username: ");
    // Store user interaction
    scanf("%s", &name);
    // Print message
    printf("Hey %s!\n",name);
    return 0;
}