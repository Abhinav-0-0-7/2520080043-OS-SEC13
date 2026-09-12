#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    char buf[100];
    mkfifo("fifo", 0666);

    if (fork() == 0) {
        int fd = open("fifo", O_RDONLY);
        read(fd, buf, sizeof(buf));
        printf("Server received: %s\n", buf);
        close(fd);
    } else {
        int fd = open("fifo", O_WRONLY);
        char msg[] = "Hello Server";
        write(fd, msg, strlen(msg) + 1);
        close(fd);
        wait(NULL);
        unlink("fifo");
    }
    return 0;
}
