#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	pid_t pid;
	char command[50];
	
	printf("Enter command: ");
	scanf("%49s", command);
	
	printf("Parent process: \n");
	printf("PID: %d\n", getpid());
	printf("PPID: %d\n", getppid());
	
	pid = fork();
	
	if (pid < 0) {
		printf("Fork() invocation failed\n");
		exit(1);
	} else if (pid == 0) {
		printf("Child Process: %d\n", getpid());
		printf("PID: %d\n", getpid());
		printf("PPID: %d\n", getppid());
		
		execlp(command, command, NULL);
		
		printf("exec() failed\n");
		exit(1);
	} else {
		printf("Parent Process\n");
		wait(NULL);
		printf("Parent Resumed\n");
		printf("Child process finished\n");
		exit(0);
	}
	return 0;
	}
