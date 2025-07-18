#include <fcntl.h>     // open
#include <unistd.h>    // close
#include <stdio.h>     // printf
#include <stdlib.h>    // free
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
char *get_next_line(int fd); // your function prototype

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    char *line;
    printf("BUFFER_SIZE: %i\n", BUFFER_SIZE);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}
