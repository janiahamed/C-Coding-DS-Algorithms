#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
void main() {
    int socket_fd = 0;
    struct sockaddr_in server = {0};
    char buf[100];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("\nClient socket creation failed!");
        return;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8888);
    server.sin_family = AF_INET;

    if (connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("\nClient to Server connect failed!");
        return;
    }
    send(socket_fd, "Hi from Client", strlen("Hi from Client"),0);
    recv(socket_fd, &buf, sizeof(buf),0);
    printf("\nReceived from Server: %s",buf);
    close(socket_fd);
}
