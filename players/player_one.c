/*
** EPITECH PROJECT, 2018
** j1.c
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

void make_connection(int signum, siginfo_t *info, void *ucontext)
{
    (void) signum;
    (void) ucontext;
    glob.enemy_pid = info->si_pid;
    my_putstr("enemy connected\n\n");
}

void who_sig_me_player_one(void)
{
    int pid = getpid();

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
    if (glob.enemy_pid != 0) {
        kill(glob.enemy_pid, SIGUSR2);
    } else {
        pause();
        kill(glob.enemy_pid, SIGUSR2);
    }
}