#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void grandChild() {
    pid_t grandPaPid = getpid();
    pid_t childPid, grandChildPid, brother;
    if ((childPid = fork()) == 0) {
        if ((grandChildPid = fork()) == 0) {
            printf("Young child's pid is %d, %d is grand child's pid.\n", getpid(), getppid());
        } else {
            printf("Grand child's pid is %d, %d is young siblings' pid, %d is parent's pid.\n", getpid(), grandChildPid, getppid());
        }
    } else if ((brother = fork())  == 0){
        printf("Brother's pid is %d, %d is parent's pid.\n", getpid(), getppid());
        }
     else {
        printf("Parent's pid is %d, %d grand child's pid.\n", getpid(), childPid);
    }
}

int main() {
    int myPid = getpid();
    printf("Parent's pid is: %d\n", myPid);
    getchar();
    grandChild();
    getchar();
    return 0;
}