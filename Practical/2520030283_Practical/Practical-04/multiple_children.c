#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int i;
    pid_t pid;

    for (i = 1; i <= 3; i++) {
        pid = fork();

        if (pid == 0) {
            printf("Child %d: PID = %d\n", i, getpid());
            sleep(i);
            printf("Child %d finished\n", i);
            exit(0);
        }
    }

    printf("Parent: waiting for children...\n");

    for (i = 0; i < 3; i++) {
        pid = wait(NULL);
        printf("Parent: Child with PID %d completed\n", pid);
    }

    printf("All children completed. Parent exiting.\n");

    return 0;
}
