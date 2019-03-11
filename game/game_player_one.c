/*
** EPITECH PROJECT, 2018
** game_player_one.c
** File description:
** No description
*/

#include <stdlib.h>
#include "my.h"
#include "pid.h"

void get_attack(char *get_order, int hits, char **field, char **field_shoot)
{
    get_order = order_give();
    hits = check_attack(field, get_order);
    usleep(200000);
    if (hits == 1) {
        kill(glob.enemy_pid, SIGUSR1);
        my_putstr(get_order);
        my_putstr(": hit\n\n");
    } else {
        kill(glob.enemy_pid, SIGUSR2);
        my_putstr(get_order);
        my_putstr(": missed\n\n");
    }
    my_putstr("my positions:\n");
    print_game_board(field);
    my_putstr("enemy's positions:\n");
    print_game_board(field_shoot);
}

int game_player_one(char **field, char **field_shoot)
{
    char *get_order = NULL;
    int hits = 0;
    int turn = 0;

    while (1) {
        if (check_loose(field) == 2) return (2);
        if (turn % 2 == 0) {
            attack(field, field_shoot);
        } else
            get_attack(get_order, hits, field, field_shoot);
        if (check_win(field_shoot) == 1) return (1);
        turn += 1;
    }
}