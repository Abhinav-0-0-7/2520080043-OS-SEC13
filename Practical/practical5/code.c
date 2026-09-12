#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int p[2];
    char msg[] = "Hello from Parent";
    char buf[50];

    pipe(p);

    if (fork() == 0) {
        close(p[1]);
        read(p[0], buf, sizeof(buf));
        printf("Child consumed: %s\n", buf);
        close(p[0]);
    } else {
        close(p[0]);
        write(p[1], msg, strlen(msg) + 1);
        close(p[1]);
        wait(NULL);
    }
    return 0;
}
