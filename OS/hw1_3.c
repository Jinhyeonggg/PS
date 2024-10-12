#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int flag = 0;

    int rc = fork();
    
    if (rc < 0) {
        printf("error occured in fork\n");
    }

    else if (rc == 0) {
        printf("hello\n");
        flag = 1;
    }

    else {
        while (1) {
            if (flag == 1) {
                printf("goodbye\n");
            }
            break;
        }
    }
    return 0;
}