#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    
    int rc1 = fork();

    if (rc1 < 0) {
        printf("error occurred in fork\n");
    }
    else if (rc1 == 0) {
        dup2(1, fd[0]);
        printf("hi, %d\n", (int)getpid());
    }
    else {
        int rc2 = fork();
        if (rc2 < 0) {
            printf("error occurred in fork\n");
        }
        else if (rc2 == 0) {
            dup2(fd[1], 0);
            char buf [100];
            read(0, &buf, 100);
            printf("%s\n", buf);
            printf("%d\n", (int)getpid());
        }
        else {
            return 0;
        }
    }
    return 0;
}