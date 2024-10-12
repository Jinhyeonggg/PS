#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc1 = fork();
    
    if (rc1 < 0) {
        printf("error occured in fork\n");
    }

    else if (rc1 == 0) {
        printf("hello from child\n");
        return 0;
    }

    else {
        int rc2 = fork();
        if (rc2 == 0){
            printf("hello from grandhild\n");
            return 0;
        }
        else {
            int grandchild = waitpid(rc2, NULL, 0);
            printf("%d is dead\n", grandchild);
        }
    }
    return 0;
}