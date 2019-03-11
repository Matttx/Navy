/*
** EPITECH PROJECT, 2018
** game_player_two.c
** File description:
** No description
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "pid.h"

void hit_function(int signum)
{
    if (signum == SIGUSR1) {
        my_putstr("hit\n\n");
        glob.binary = 1;
    }
    else {
        my_putstr("missed\n\n");
        glob.binary = 0;
    }
}

int attack(char **field, char **field_shoot)
{
    char *signal = NULL;
    char *order = NULL;
    struct sigaction hit;

    hit.sa_flags = SA_SIGINFO;
    hit.sa_handler = hit_function;
    my_putstr("attack: ");
    if ((order = get_line(0)) == NULL) return (84);
    if (check_order(order) == 1) {
        my_putstr("wrong position\n");
        attack(field, field_shoot);
    } else {
        my_putstr(order);
        my_putstr(": ");
        for (int i = 0; order[i] != '\0'; push_signal(signal), i++)
            signal = convert_base_two(order[i]);
        sigaction(SIGUSR1, &hit, NULL);
        sigaction(SIGUSR2, &hit, NULL);
        pause();
        check_shoot(field_shoot, order);
    } return (0);
}

void get_attack_two(char *get_order, int hit, char **field)
{
    get_order = order_give();
    hit = check_attack(field, get_order);
    usleep(200000);
    if (hit == 1) {
        kill(glob.enemy_pid, SIGUSR1);
        my_putstr(get_order);
        my_putstr(": hit\n\n");
    } else {
        kill(glob.enemy_pid, SIGUSR2);
        my_putstr(get_order);
        my_putstr(": missed\n\n");
    }
}

int game_player_two(char **field, char **field_shoot)
{
    char *get_order = NULL;
    int turn = 0;
    int hit = 0;

    while (1) {
        if (check_loose(field) == 2) return (2);
        if (turn % 2 == 1) {
            attack(field, field_shoot);
            my_putstr("my positions:\n");
            print_game_board(field);
            my_putstr("enemy's positions:\n");
            print_game_board(field_shoot);
        } else
            get_attack_two(get_order, hit, field);
        if (check_win(field_shoot) == 1) return (1);
        turn += 1;
    }
}