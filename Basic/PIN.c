#include <stdio.h>

int main(void) {
    // Declare pin as interger
    int pin;
    // The key
    int key = 1410; 
    // Asking the user enter a valid pin
    printf("Enter your PIN: ");
    // Store pin
    scanf("%d", &pin);

    // If the pin is right, the user will receive a success message
    if (pin == key) {
        printf("OK, Success!\n");
    } else {
        printf("Incorrect PIN.\n");
    }
    return 0;
}