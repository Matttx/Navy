/*
** EPITECH PROJECT, 2018
** my_strconcat.c
** File description:
** No description
*/

#include <stdlib.h>

char *my_strconcat(char a, char b)
{
    char *str;

    str = malloc(sizeof(char) * 3);
    str[0] = a;
    str[1] = b;
    str[2] = '\0';
    return (str);
}