#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void createChild() {
    fork();
}

void childPid(int inputPid) {
    int childPid = getpid();
    if (childPid != inputPid) {
        printf("PID child is: %d\n", childPid);
    }
}

void anotherChildPid(int inputPidMy) {
    int anotherPid = getpid();
    if (anotherPid != inputPidMy) {
        printf("PID child is: %d\n", anotherPid);
    }
}

void anotherParentPid(int inputPidMy, int inputPidChild) {
    int anotherParentPid = getppid();
    // if (anotherParentPid)

}

void parentPid(int inputPid) {
    int parentPid = getppid();
    if (parentPid == inputPid) {
        printf("PID parent is: %d\n", parentPid);
    }
}

void newFunction() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Error");
    } else if (pid == 0) {
        printf("Child is having pid %d\n", getpid());
        printf("My Parent's pid is %d\n", getppid());
    } else {
        printf("Parent is having pid %d\n", getpid());
        printf("My Child's pid is %d\n", pid);
    }
}

void grandChild() {
    pid_t grandPaPid = getpid();
    pid_t childPid;
    if ((childPid = fork()) == 0) {
        pid_t parentPid = getpid();
        pid_t grandChildPid;
        if ((grandChildPid = fork()) == 0) {
            printf("Young child's pid is %d, %d is grand child's pid.\n", getpid(), parentPid);
        } else {
            printf("Grand child's pid is %d, %d is young siblings' pid.\n", getpid(), grandChildPid);
        }
    } else {
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