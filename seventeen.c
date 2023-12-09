#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
typedef struct msg_buf {
    long type;
    char msg[100];
}msg_t;
void main() {
    msg_t ms;
    key_t key = ftok("Allah",123);
    int msg_id = msgget(key, 0666|IPC_CREAT);
    msgrcv(msg_id,&ms, sizeof(ms),1,0);
    printf("%s",ms.msg);
}
