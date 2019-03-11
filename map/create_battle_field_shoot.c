/*
** EPITECH PROJECT, 2018
** create_battle_field_shoot.c
** File description:
** No description
*/

#include <stdlib.h>
#include "my.h"

char **complete_field_shoot(char **field)
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
    return (field);
}

char **create_battle_field_shoot(char **field)
{
    int i = 0;

    field = malloc(sizeof(char *) * (9));
    while (i != (9)) {
        field[i] = malloc(sizeof(char) * 9);
        i++;
    }
    field = complete_field_shoot(field);
    return (field);
}