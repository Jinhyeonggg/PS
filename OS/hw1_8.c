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
        printf("here %d\n", (int)getpid());
        dup2(fd[1], 1);
        printf("hifefefef, %d\n", (int)getpid());
    }
    else {
        int rc2 = fork();
        if (rc2 < 0) {
            printf("error occurred in fork\n");
        }
        else if (rc2 == 0) {
            char buf [10000];
            dup2(fd[0], 0);
            read(STDIN_FILENO, &buf, 10000);
            printf("%s\n", buf);
            printf("%d\n", (int)getpid());
        }
        else {
            return 0;
        }
    }
    return 0;
}