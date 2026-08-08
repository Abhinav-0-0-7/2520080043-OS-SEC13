#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[1024];
    int n;

    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Error opening source file\n");
        return 1;
    }

    destination = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (destination < 0)
    {
        printf("Error opening destination file\n");
        close(source);
        return 1;
    }

    while ((n = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, n);
    }

    close(source);
    close(destination);

    printf("File copied successfully\n");

    return 0;
}
