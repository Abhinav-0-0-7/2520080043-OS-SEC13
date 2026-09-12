#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p[2];
    pipe(p);

    if (fork() == 0) {
        dup2(p[0], 0);
        close(p[0]);
        close(p[1]);
        execlp("grep", "grep", ".c", NULL);
    } else {
        dup2(p[1], 1);
        close(p[0]);
        close(p[1]);
        execlp("ls", "ls", "-l", NULL);
        wait(NULL);
    }
    return 0;
}
