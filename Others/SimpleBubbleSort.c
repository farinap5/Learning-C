/*
This program generates a array randomly
and organizes showing step by step.
Bubble Sort.

Example:
Array generated:
10 1 6 5 8 9 7 2 3 4

10 1 6 5 8 9 7 2 3 4
10 <- 1
1 10 6 5 8 9 7 2 3 4
10 <- 6
1 6 10 5 8 9 7 2 3 4
10 <- 5
1 6 5 10 8 9 7 2 3 4
6 <- 5
1 5 6 10 8 9 7 2 3 4

When it is done:
1 2 3 4 5 6 7 8 9 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int m[10];

    srand(time(NULL));

    // Generate a valid matrix without repeated numbers.
    for(int i=0;i < 10;i++) {
        int x, y;
        do {
            y = 0;
            x = (rand()%10)+1;
            for(int j=0;j<10;j++) {
                if (x == m[j])
                    y++;
            }
        } while (y != 0);
        m[i] = x;
    }
    //--------------------------------------------------
    for(int i=0;i < 10;i++)
        printf("%d ",m[i]);
    printf("\n");

    int y;
    do {
        y = 0;
        for(int i=0;i < 10;i++) {
            if(m[i] > m[i+1] && i != 9) {
                printf("%d <- %d\n",m[i],m[i+1]);
                int z = m[i];
                m[i] = m[i+1];
                m[i+1] = z;
                y++;
                break;
            }
        }
        for(int i=0;i < 10;i++)
            printf("%d ",m[i]);
        usleep(1000000);
        printf("\n");
    } while(y != 0);

    return 0;
}
