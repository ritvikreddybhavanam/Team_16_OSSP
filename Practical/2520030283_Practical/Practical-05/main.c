#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<time.h>

int main() {
    int fd[2];
    char msg[] = "Hello from parent";
    char buffer[100];

    pipe(fd);

    clock_t start = clock();

    int pid = fork();

    if (pid == 0) {
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));

        printf("Child consumed: %s\n", buffer);

        close(fd[0]);
    } else {
        close(fd[0]);

        printf("Parent produced: %s\n", buffer);

        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);
    }
}