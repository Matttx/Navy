/*
** EPITECH PROJECT, 2019
** read_file.c
** File description:
** file which contain the read and the error gestion of the file in My Navy
*/

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int manage_other_error(char *buff)
{
    int i = 0;

    while (buff[i] != '\0') {
        if (i % 8 == 0 && (buff[i] < '2' || buff[i] > '5'))
            return (84);
        if ((i % 8 == 1 || i % 8 == 4) && (buff[i] != ':'))
            return (84);
        if ((i % 8 == 2 || i % 8 == 5) && (buff[i] < 'A' || buff[i] > 'H'))
            return (84);
        if ((i % 8 == 3 || i % 8 == 6) && (buff[i] < '1' || buff[i] > '8'))
            return (84);
        if ((i % 8 == 7) && (buff[i] != '\n'))
            return (84);
        i++;
    } return (0);
}

int manage_error_file(char *buff)
{
    int i = 0;
    int row = 0;
    int return_value = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            row++;
        i++;
    }
    if (row != 4)
        return_value = 84;
    else
        return_value = manage_other_error(buff);
    return (return_value);
}

int check_nb_boat(char *buff)
{
    int tab[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tab[j] == buff[i * 8] - 48)
                return (84);
        }
        tab[i] = buff[i * 8] - 48;
    }
    return (0);
}

int read_file_player_two(char **argv, char *buff)
{
    int fd = 0;
    ssize_t size = 0;
    int return_value = 0;

    fd = open(argv[2], O_RDONLY);
    size = read(fd, buff, 32);
    buff[size] = '\0';
    if (size == -1) {
        close(fd);
        return (84);
    }
    return_value = manage_error_file(buff);
    if (check_nb_boat(buff) == 84) return (84);
    return (return_value);
}

int read_file_player_one(char **argv, char *buff)
{
    int fd = 0;
    ssize_t size = 0;
    int return_value = 0;

    fd = open(argv[1], O_RDONLY);
    size = read(fd, buff, 32);
    buff[size] = '\0';
    if (size == -1) {
        close(fd);
        return (84);
    }
    return_value = manage_error_file(buff);
    if (check_nb_boat(buff) == 84) return (84);
    return (return_value);
}