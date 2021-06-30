#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// payload 1
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa <- 45 / 97

// Payload 2
//aaaaaaaaaaaaaaaaaaaaaaaaaaaahgfe

void sF() {
    char a = 'A';
    char b = 'B';
    char c = 'C';
    char d = 'D';
    char e = 'E';
    char f = 'F';
    char g = 'G';
    char h = 'H';
    char i = 'I';
    char j = 'J';
    char k = 'K';
    char l = 'L';

    char a1 = 'a';
    char b1 = 'b';
    char c1 = 'c';
    char d1 = 'd';
    char e1 = 'e';
    char f1 = 'f';
    char g1 = 'g';
    char h1 = 'h';
    char i1 = 'i';
    char j1 = 'j';
    char k1 = 'k';
    char l1 = 'l';

    printf("%c",f);
    printf("%c",l1);
    printf("%c",a1);
    printf("%c: ",g);
    printf("%c",k1);
    printf("%c",h);
    printf("%c",a);
    printf("%c",k);
    printf("%c",l1);
    printf("%c",a1);
    printf("%c",c1);
    printf("%c",j);
    printf("%c",b);
    printf("%c\n",j);
}

void pwn(void) {
    volatile int mod;
    do {
        mod = 0;
        char buff[16];

        gets(buff);

        if (mod == 0x65666768) {
            printf("Wooww! You are good!\n");
            sF();
        } else {
            printf("Try again, you got 0x%08x, 0x65666768 is expected!\n",mod);
        }
    } while(mod != 0x65666768);
}

void methodAllowed(void) {
    char za[8] = "a2lyaXRv";
    char buff[30];
    int correct_key = 0;

    printf("Enter your password: ");
    gets(buff);

    if (correct_key != 0) {
        printf("Correct Password!\n");
        pwn();
    } else {
        printf("Wrong Password!\n");
    }
}

int main(void) {
    char *env;
    env = getenv("SEC");

    if (!env) {
        printf("This system doesn't look secure!\n");
    } else {
        if (env[0] == 't' && env[1] == 'r' && env[2] == 'u' && env[3] == 'e') {
            printf("[OK]- ");
            methodAllowed();
        } else {
            printf("This system doesn't look secure!!\n");
        }
    }
}