#include<stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MQ_KEY 0x1423

typedef struct msg {
    long type;
    int n1;
    int n2;
}msg_t;

int main(){
    int mqid, ret, s,a,b;
    mqid=msgget(MQ_KEY, IPC_CREAT | 0600);
    if(mqid<0){
        perror("Msg queue failed");
        _exit(0);
    }
    ret=fork();
    if(ret == 0){
        msg_t m1;
        m1.n1 = 2;
        m1.n2 = 8;
        m1.type=1;
        printf("Sending child data\n");
        ret = msgsnd(mqid, &m1, sizeof(m1),0);
        printf("Child Message sent\n");

        ret = msgrcv(mqid, &m1, sizeof(m1), 1, 0);
        printf("Child: Sum of Numbers = %d\n", m1.n1);
        _exit(0);
    }
    else{
        msg_t m2;
        printf("Parent: Waiting for Msg\n");
        ret=msgrcv(mqid, &m2, sizeof(m2), 1, 0);
        printf("Parent: Msg Received\n");
        m2.n1+=m2.n2;
        ret=msgsnd(mqid, &m2, sizeof(m2), 0);
        printf("Parent: Processed Data Sent\n");
        wait(&s);
        msgctl(mqid, IPC_RMID, NULL);
        printf("Msg Queue Destroyed\n");

    }
    return 0;
}