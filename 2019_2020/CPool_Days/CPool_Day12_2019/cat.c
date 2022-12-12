/*
** EPITECH PROJECT , 2019
** cat
** File description :
**
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    int fd;
    int size;
    char buffer[32];
    int i = 1;

    while (i < ac)
    {
        fd = open(av[i], O_RDONLY);
        size = read(fd, buffer, 32);
        buffer [size - 1] = '\n';
        buffer [size] = '\0';
        write (1, buffer, size);
        close (fd);
    }
    return (0);
}