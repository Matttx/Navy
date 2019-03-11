/*
** EPITECH PROJECT, 2018
** get_line.c
** File description:
** No description
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_line(int fd)
{
    ssize_t size = 0;
    char a[1];
    int i = 0;
    char *buff = malloc(sizeof(char) * 100);

    size = read(fd, a, 1);
    if (size == -1 || size == 0)
        return (NULL);
    while (a[0] != '\n') {
        buff[i] = a[0];
        i++;
        size = read(fd, a, 1);
        if (size == -1)
            return (NULL);
    }
    buff[i] = '\0';
    return (buff);
}