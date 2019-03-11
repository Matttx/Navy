/*
** EPITECH PROJECT, 2018
** j2.c
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

void apply_connection(int signum, siginfo_t *info, void *ucontext)
{
    (void) signum;
    (void) ucontext;
    (void) info;
    my_putstr("successfully connected\n\n");
}

void who_sig_me_player_two(char **av)
{
    struct sigaction player2;
    int pid = getpid();
    glob.enemy_pid = my_raws(av[1]);

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    player2.sa_flags = SA_SIGINFO;
    player2.sa_sigaction = apply_connection;
    sigaction(SIGUSR2, &player2, NULL);
    kill(glob.enemy_pid, SIGUSR1);
    pause();
}