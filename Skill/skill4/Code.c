#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t p[2];

    for(i = 0; i < 2; i++) {
        p[i] = fork();

        if(p[i] == 0) {
            printf("Child %d: PID=%d\n", i+1, getpid());
            sleep(2);
            return 0;
        }
    }

    wait(NULL);
    waitpid(p[1], NULL, 0);

    printf("All children completed\n");
    return 0;
}
