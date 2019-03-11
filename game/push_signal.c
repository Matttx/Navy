/*
** EPITECH PROJECT, 2018
** push_signal.c
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

void wait_function(int signum)
{
    (void) signum;
}

void push_signal(char *signal)
{
    struct sigaction wait_sign;

    wait_sign.sa_flags = SA_SIGINFO;
    wait_sign.sa_handler = wait_function;
    sigaction(SIGUSR2, &wait_sign, NULL);
    for (int i = 0; i < 8; i++) {
        if (signal[i] == '1')
            kill(glob.enemy_pid, SIGUSR1);
        else
            kill(glob.enemy_pid, SIGUSR2);
        if (usleep(200000) == 0)
            i--;
    }
}