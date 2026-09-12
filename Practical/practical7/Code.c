#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 10;
static int stat = 20;

void code() {}

int main() {
    int stack = 30;
    int *heap = malloc(sizeof(int));

    printf("Code  : %p\n", (void *)code);
    printf("Global: %p\n", (void *)&global);
    printf("Static: %p\n", (void *)&stat);
    printf("Heap  : %p\n", (void *)heap);
    printf("Stack : %p\n", (void *)&stack);

    printf("Check /proc/%d/maps\n", getpid());

    free(heap);
    return 0;
}
