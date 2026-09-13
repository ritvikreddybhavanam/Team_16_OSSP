#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    char buffer[100];

    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_RDONLY);

    while (1)
    {
        int n = read(fd, buffer, sizeof(buffer) - 1);

        if (n <= 0)
            break;

        buffer[n] = '\0';

        printf("Server received: %s\n", buffer);
    }

    close(fd);

    return 0;
}