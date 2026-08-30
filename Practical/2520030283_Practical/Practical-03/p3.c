#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	pid_t pid;
	pid = fork();
	
	printf("Parent process\n");
    printf("Parent PID  : %d\n", getpid());
    printf("Parent PPID : %d\n", getppid());
	
	if (pid < 0) {
		printf("Fork() Failed\n");
		exit(1);
	} else if (pid == 0) {	
		printf("Child Process\n");
		printf("Child PID: %d\n", getpid());
		printf("Child PPID: %d\n", getppid());
	} else {
		wait(NULL);
		printf("Parent Process\n");
		printf("Parent PID: %d\n", getpid());
		printf("Parent PPID: %d\n", getppid());
	}
	
	return 0;
}
