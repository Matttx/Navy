/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** tool
*/

#include <stdlib.h>
#include "my.h"

char *convert_base_two(int nb)
{
    char *buff = malloc(sizeof(char) * 10);

    for (int i = 0; i < 8; i++) {
        for (; nb >= 2; i++) {
            buff[i] = nb % 2 + 48;
            nb /= 2;
        }
        do {
            buff[i] = nb + 48;
            i++;
        } while (nb >= 2);
        for (; i < 8; i++)
            buff[i] = '0';
    }
    my_revstr(buff);
    return (buff);
}