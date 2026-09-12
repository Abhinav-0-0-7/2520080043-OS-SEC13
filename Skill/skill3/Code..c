#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: PID=%d PPID=%d\n", getpid(), getppid());
        sleep(5);
        printf("Child: Running\n");
    }
    else {
        printf("Parent: PID=%d Child PID=%d\n", getpid(), pid);
        printf("Parent: Waiting\n");
        wait(NULL);
        printf("Parent: Child terminated\n");
    }

    return 0;
}
