#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char message[100];

    int fd = open("myfifo", O_WRONLY);

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    write(fd, message, strlen(message) + 1);

    close(fd);

    return 0;
}