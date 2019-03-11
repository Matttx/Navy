/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of My Navy
*/

#include <stdlib.h>
#include "my.h"
#include "pid.h"

global_t glob;

void make_connection(int signum, siginfo_t *info, void *ucontext);

int gameplay_one(char **field, char **field_shoot)
{
    int result = 0;

    who_sig_me_player_one();
    my_putstr("my positions:\n");
    print_game_board(field);
    my_putstr("enemy's positions:\n");
    print_game_board(field_shoot);
    result = game_player_one(field, field_shoot);
    if (result == 1) return (1);
    else if (result == 2) return (2);
    return (0);
}

int gameplay_two(char **av, char **field, char **field_shoot)
{
    int result = 0;

    who_sig_me_player_two(av);
    my_putstr("my positions:\n");
    print_game_board(field);
    my_putstr("enemy's positions:\n");
    print_game_board(field_shoot);
    result = game_player_two(field, field_shoot);
    if (result == 1) return (1);
    else if (result == 2) return (2);
    return (0);
}

int game_one(char **field, char **field_shoot, char *buff)
{
    int result = 0;

    if (check_pos(buff) == 84) return (84);
    field = create_battle_field(field, buff);
    field_shoot = create_battle_field_shoot(field_shoot);
    if (field == NULL) return (84);
    result = gameplay_one(field, field_shoot);
    if (result == 84) return (84);
    my_putstr("my positions:\n");
    print_game_board(field);
    my_putstr("enemy's positions:\n");
    print_game_board(field_shoot);
    if (result == 1)
        my_putstr("\nI won\n");
    else if (result == 2)
        my_putstr("\nEnemy won\n");
    return (0);
}

int game_two(char **av, char **field, char **field_shoot, char *buff)
{
    int result = 0;

    if (check_pos(buff) == 84) return (84);
    field = create_battle_field(field, buff);
    field_shoot = create_battle_field_shoot(field_shoot);
    if (field == NULL) return (84);
    result = gameplay_two(av, field, field_shoot);
    if (result == 84) return (84);
    my_putstr("my positions:\n");
    print_game_board(field);
    my_putstr("enemy's positions:\n");
    print_game_board(field_shoot);
    if (result == 1)
        my_putstr("\nI won\n");
    else if (result == 2)
        my_putstr("\nEnemy won\n");
    return (0);
}

int main(int ac, char **av)
{
    char **field = NULL;
    char **field_shoot = NULL;
    char buff[32];
    struct sigaction player1;

    if (helper(ac, av) == 1) return (0);
    if (ac == 2) {
        player1.sa_flags = SA_SIGINFO;
        player1.sa_sigaction = make_connection;
        sigaction(SIGUSR1, &player1, NULL);
        if (read_file_player_one(av, buff) == 84) return (84);
        if (game_one(field, field_shoot, buff) == 84) return (84);
    } else if (ac == 3) {
        if (read_file_player_two(av, buff) == 84) return (84);
        if (game_two(av, field, field_shoot, buff) == 84) return (84);
    } else
        return (84);
}