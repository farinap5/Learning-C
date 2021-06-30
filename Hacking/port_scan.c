#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int meusocket;
    int connectt;


    int port;
    int init = 1;
    int fnl = 1024;
    char *target;
    target = argv[1];


    struct  sockaddr_in alvo;
    for (port = init;port < fnl;port++) {
        meusocket = socket(AF_INET, SOCK_STREAM, 0);
        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(port);
        alvo.sin_addr.s_addr = inet_addr(target);

        connectt = connect(meusocket,(struct sockaddr *)&alvo, sizeof alvo);

        if (connectt == 0) {
            printf("%d - Port Opened <-\n",port);
            close(meusocket);
            close(connect);
        } else {
            //printf("Port Closed\n");
            close(meusocket);
            close(connect);
        }
    }

    return 0;
}
