// sizeof is called when we need to know the size
// of a variable in the value of bytes of the memory.
// sizeof(variable)

#include<stdio.h>

// Main function
int main() {
    // Declare variable
    int a = 5;
    char b = 'A';
    char c[50] = "hello world";


    printf("Size of a : %lu Bytes\n" ,sizeof(a));
    printf("Size of A in b : %lu Bytes\n",sizeof(b));
    // The value of c does not match the number of characters 
    // "hello world" occupied, however we are reserving 50 bytes in memory.
    printf("Size of c : %lu Bytes\n",sizeof(c));

    return 0;

}
