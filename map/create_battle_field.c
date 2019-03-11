/*
** EPITECH PROJECT, 2019
** create_battle_field.c
** File description:
** file which create and full the field in My Navy
*/

#include <stdlib.h>
#include "my.h"

char **complete_field(char **field, char *buff)
{
    int i = 0;
    int j = 0;

    while (j != 8) {
        while (i < 8) {
            field[j][i] = '.';
            i++;
        }
        field[j][i] = '\n';
        i = 0;
        j++;
    }
    fill_position(field, buff);
    return (field);
}

char **create_battle_field(char **field, char *buff)
{
    int i = 0;

    field = malloc(sizeof(char *) * (9));
    while (i != (9)) {
        field[i] = malloc(sizeof(char) * 9);
        i++;
    }
    field = complete_field(field, buff);
    if (check_boat(field) == 84) return (NULL);
    if (check_size(field) == 84) return (NULL);
    return (field);
}