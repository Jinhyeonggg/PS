#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    const char *fileName = "testFile";
    int fd = open(fileName, O_RDWR);  // Correct flag usage
    int rc = fork();

    if (rc < 0) {
        printf("error occurred in fork\n");
    }

    else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("child closed standard output\n");
    }

    else {
        int child = wait(NULL);
        printf("hello from parent\n");
    }
    return 0;
}