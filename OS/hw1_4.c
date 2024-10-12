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
        printf("hello from child\n");

        char *argv[] = {"ls", "-al", NULL};
        execvp("ls", argv);
    }

    else {
        int child = wait(NULL);
    }
    return 0;
}