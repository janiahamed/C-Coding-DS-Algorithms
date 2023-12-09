#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 10
void *handle_client(void *arg) {
    int client_fd = *((int *)arg);
    char buffer[100];
    printf("\nClient connected!");
    send(client_fd, "Hi from Server!", strlen("Hi from Server!"), 0);
    recv(client_fd, buffer, sizeof(buffer),0);
    printf("\nClient sent : %s", buffer);
    close(client_fd);
    pthread_exit(NULL);
}
void main() {
    printf("\nSERVER INITIALIZING!");
    int server_fd = 0;
    int connected_fd = 0;
    struct sockaddr_in server_addr = {0};
    pthread_t tid[MAX];
    static int i = 0;
    int opt = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("\nServer Socket creation failed!");
        return;
    }
   
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("\nSocket option set failed!");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);
    struct sockaddr_in client_addr;
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("\nServer Bind failed!");
        return;
    }

    listen(server_fd, MAX);
    int addlen = sizeof(struct sockaddr_in);
    while(1) {
        if ((connected_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addlen)) < 0) {
            perror("\nClient connection failed!");
            return;
        }

        pthread_create(&tid[i], NULL, handle_client, (void *)&connected_fd);
        i = (i+1)%MAX;
    }
    close(server_fd);
}
