#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();
    
    if (rc < 0) {
        printf("error occured in fork\n");
    }

    else if (rc == 0) {
        int x = wait(NULL);
        printf("%d is dead?\n", x);
    }

    else {
        int child = wait(NULL);
        printf("%d is dead\n", child);
    }
    return 0;
}