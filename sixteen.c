#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
typedef struct msg_buffer {
    long type;
    char buffer[100];
}msg_t;
void main() {
    msg_t ms;
    key_t key = ftok("Allah",123);
    int msg_id = 0;
    msg_id = msgget(key,0666|IPC_CREAT);
    ms.type = 1;
    strncpy(ms.buffer,"HELLO DUDE!", sizeof("HELLO DUDE!"));
    msgsnd(msg_id, &ms, sizeof(ms), 0);
}
