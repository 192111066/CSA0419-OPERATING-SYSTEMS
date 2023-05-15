#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid1, pid2, pid3, pid4;

    pid1 = fork(); // create first child process

    if (pid1 == 0) { // first child process
        printf("Printing odd numbers: \n");
        for (int i = 1; i <= 10; i += 2) {
            printf("%d\n", i);
        }
        printf("Process ID: %d\n", getpid());
        exit(0);
    }

    pid2 = fork(); 

    if (pid2 == 0) { 
        printf("Printing even numbers: \n");
        for (int i = 2; i <= 10; i += 2) {
            printf("%d\n", i);
        }
        printf("Process ID: %d\n", getpid());
        exit(0);
    }

    pid3 = fork(); 

    if (pid3 == 0) {
        printf("Printing multiples of 3: \n");
        for (int i = 3; i <= 30; i += 3) {
            printf("%d\n", i);
        }
        printf("Process ID: %d\n", getpid());
        exit(0);
    }

    pid4 = fork(); 

    if (pid4 == 0) { // fourth child process
        printf("Printing multiples of 5: \n");
        for (int i = 5; i <= 50; i += 5) {
            printf("%d\n", i);
        }
        printf("Process ID: %d\n", getpid());
        exit(0);
    }

    return 0;
}
