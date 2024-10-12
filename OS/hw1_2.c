#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    const char *fileName = "testFile";
    int fd = open(fileName, O_RDWR);  // Correct flag usage
    int rc = fork();

    if (rc < 0) {
        printf("error occurred in fork\n");
    }

    else if (rc == 0) {
        char *a = "hello from child\n";
        write(fd, a, strlen(a));  // Write correct number of bytes
        close(fd);
    }

    else {
        char *a = "hello from parent\n";
        write(fd, a, strlen(a));  // Write correct number of bytes
        close(fd);
    }
    return 0;
}