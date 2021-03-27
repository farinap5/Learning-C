/*
This section contains a series of mathematical examples 
involving values ​​of the circumference that must be found from a radius.
*/
#include <stdio.h>

// Define a value for PIE.
#define PIE 3.14;

int main(void) {
    // Declare variables.
    // Floating points because this math will
    // hardly have only integers numbers.
    float radius, area, diameter, length, radius2;

    // Show a message asking for a radius.
    printf("Enter the radius of your circle: ");
    // Store the given value as float "%f".
    scanf("%f", &radius);

    // Do the maths.
    // Diameter = 2 x radius
    diameter = 2 * radius;
    // Area = PIE x radius²
    radius2 = radius * radius;
    area =  PIE * radius2;
    // Length = 2 x PIE x radius
    length = 2 * PIE * radius;

    // Output the rusults
    printf("The radius is %f.\n", radius);
    printf("The area of the circle is %f.\n", area);
    printf("The length of the circle is %f.\n", radius);
    return 0;
}