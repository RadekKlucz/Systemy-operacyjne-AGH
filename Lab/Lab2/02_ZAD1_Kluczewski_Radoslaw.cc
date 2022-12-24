#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char strGlobal[100]; // string o 100 bajtach
int* numberGlobal = (int*)malloc(5 * sizeof(int)); // 20 bajtow zajmie

int main() 
{
    char strLocal[100];
    int* numberLocal = (int*)malloc(5 * sizeof(int)); // 20 bajtow zajmie

    int myInt1;
    printf("Input integral number: \n");
    scanf("%d", &myInt1);
    printf("%d\n", myInt1); 
    pid_t pid;

    // fork a child process
    pid = fork();    
    getchar();

    if (pid < 0) { // error occurred
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) { // child process
        printf("From Child: Parent's pid is %d, child's pid is %d\n", getppid(), getpid());
        // execlp("/bin/ls", "ls", NULL);
        int myInt2;
        printf("Input integral number: \n");
        scanf("%d", &myInt2);
        printf("%d\n", myInt2);        

    } else { // parent process
        // parent will be wait for the child to complete
        getchar();
        printf("From Parent: Parent's pid is %d, child's pid is %d\n", getppid(), getpid());
        printf("Child Complete\n");
    }
    return 0;
}