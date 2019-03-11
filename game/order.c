/*
** EPITECH PROJECT, 2018
** order.c
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

void recept_signal(int signum)
{
    usleep(20000);
    kill(glob.enemy_pid, SIGUSR2);
    if (signum == SIGUSR1)
        glob.binary = 1;
    else if (signum == SIGUSR2)
        glob.binary = 0;
}

char receive_message(void)
{
    char signal[8];
    char pos = 0;
    struct sigaction recept_order;

    recept_order.sa_flags = SA_SIGINFO;
    recept_order.sa_handler = recept_signal;
    sigaction(SIGUSR1, &recept_order, NULL);
    sigaction(SIGUSR2, &recept_order, NULL);
    for (int i = 0; i < 8; i++) {
        glob.binary = -1;
        pause();
        if (glob.binary == -1)
            i--;
        else
            signal[i] = glob.binary + 48;
    }
    pos = binary_to_decimal(signal);
    return (pos);
}

char *order_give(void)
{
    char *positions;
    char pos_x = 0;
    char pos_y = 0;

    my_putstr("waiting for enemy's attack...\n");
    pos_x = receive_message();
    pos_y = receive_message();
    positions = my_strconcat(pos_x, pos_y);
    return (positions);
}