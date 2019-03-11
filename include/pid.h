/*
** EPITECH PROJECT, 2018
** pid.h
** File description:
** No description
*/

#ifndef PSU_NAVY_2018_PID_H
#define PSU_NAVY_2018_PID_H

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

typedef struct global_s {
    pid_t enemy_pid;
    int binary;
}global_t;

extern global_t glob;
#endif //PSU_NAVY_2018_PID_H
