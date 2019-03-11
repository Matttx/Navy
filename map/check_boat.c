/*
** EPITECH PROJECT, 2019
** check_boat.c
** File description:
** fct which check if the boat are annof or not too much on the field in My Navy
*/

#include "stdio.h"

int check_pos(char *buff)
{
    for (int i = 0; i < 4; i++) {
        if ((buff[i * 8 + 2] != buff[i * 8 + 5]) &&
            (buff[i * 8 + 3] != buff[i * 8 + 6]))
            return (84);
    }
    return (0);
}

int check_size(char **field)
{
    int five = 0;
    int four = 0;
    int three = 0;
    int two = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == '5')
                five++;
            if (field[i][j] == '4')
                four++;
            if (field[i][j] == '3')
                three++;
            if (field[i][j] == '2')
                two++;
        }
    }
    if (two != 2 || three != 3 || four != 4 || five != 5)
        return (84);
    return (0);
}

int check_loose(char **field)
{
    int cross = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 'x')
                cross++;
        }
    }
    if (cross == 14)
        return (2);
    return (0);
}

int check_win(char **field_shoot)
{
    int cross = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field_shoot[i][j] == 'x')
                cross++;
        }
    }
    if (cross == 14)
        return (1);
    return (0);
}

int check_boat(char **field)
{
    int i = 0;
    int j = 0;
    int boat = 0;

    for (; j < 8; j++)
        for (i = 0; i < 8; i++)
            if (field[j][i] >= '2' && field[j][i] <= '5')
                boat = boat + 1;
    if (boat != 14)
        return (84);
    return (0);
}