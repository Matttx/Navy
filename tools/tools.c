/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools of My Navy
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char *tab)
{
    int i = 0;

    if (tab == NULL)
        return (0);
    for (i = 0; tab[i] != '\0'; i++);

    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}