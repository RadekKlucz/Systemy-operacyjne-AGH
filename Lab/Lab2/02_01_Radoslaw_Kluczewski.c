#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


void child() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Error");
    } else if (pid == 0) {
        printf("The child has a pid %d\n", getpid());
        printf("My Parent's pid is %d\n", getppid());
    } else {
        printf("The parent has a pid %d\n", getpid());
        printf("My Child's pid is %d\n", pid);
    }
}

int main() {
    int myPid = getpid();
    printf("PID 1 is: %d\n", myPid);
    getchar();
    child();
    getchar();
    return 0;
}