#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    if (sig == SIGINT)
        printf("\nSIGINT received\n");

    if (sig == SIGTERM)
        printf("SIGTERM received\n");

    if (sig == SIGUSR1)
        printf("SIGUSR1 received\n");
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGUSR1, handler);

    printf("Process ID: %d\n", getpid());
    printf("Waiting for signals...\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}
