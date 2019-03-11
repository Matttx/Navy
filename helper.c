/*
** EPITECH PROJECT, 2018
** helper.c
** File description:
** No description
*/

#include "my.h"

int helper(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions");
            my_putstr("\nDESCRIPTION\n\tfirst_player_pid: only for the 2nd "
                        "player. pid of the first player.");
            my_putstr("\n\tnavy_positions: file representing the positions of"
                        " the ships.\n");
            return (1);
        }
    }
    return (0);
}