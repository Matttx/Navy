/*
** EPITECH PROJECT, 2019
** print_game_board.c
** File description:
** fct which print the map in My Navy
*/

#include "my.h"

void print_game_board(char **field)
{
    int i = 0;
    char number = 49;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int j = 0; j < 8; j++, number++) {
        my_putchar(number);
        my_putchar('|');
        while (i < 7) {
            my_putchar(field[j][i]);
            my_putchar(' ');
            i++;
        }
        my_putchar(field[j][i]);
        my_putchar('\n');
        i = 0;
    }
    my_putchar('\n');
}