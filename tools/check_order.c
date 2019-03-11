/*
** EPITECH PROJECT, 2019
** check_order.c
** File description:
** fct which check if the attack is valid or not in My Navy
*/

#include "my.h"
#include <stdio.h>

int check_order(char *str)
{
    int lenght = 0;

    lenght = my_strlen(str);
    if (lenght != 2)
        return (1);
    else {
        if (str[0] < 'A' || str[0] > 'H')
            return (1);
        if (str[1] < '1' || str[1] > '8')
            return (1);
    }
    return (0);
}