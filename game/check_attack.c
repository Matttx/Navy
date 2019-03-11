/*
** EPITECH PROJECT, 2019
** check_attack.c
** File description:
** fct which update the field in My Navy
*/

#include "pid.h"

int check_shoot(char **map, char *str)
{
    if (glob.binary == 1)
        map[str[1] - '1'][str[0] - 'A'] = 'x';
    else
        map[str[1] - '1'][str[0] - 'A'] = 'o';
    return (0);
}

int check_attack(char **map, char *str)
{
    int hit = 0;

    if (map[str[1] - '1'][str[0] - 'A'] >= '2' &&
        map[str[1] - '1'][str[0] - 'A'] <= '5') {
        hit = 1;
        map[str[1] - '1'][str[0] - 'A'] = 'x';
    }
    else {
        hit = 0;
        map[str[1] - '1'][str[0] - 'A'] = 'o';
    }
    return (hit);
}