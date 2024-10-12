#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 100;
    int *p = &x;
    int rc = fork();
    
    if (rc < 0) {
        printf("error occured in fork\n");
    }

    else if (rc == 0) {
        *p = 200;
        printf("child - %d", x);
    }

    else {
        *p = 300;
        printf("parent - %d", x);
    }
    return 0;
}