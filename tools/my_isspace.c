/*
** EPITECH PROJECT, 2019
** my_isspace
** File description:
** my_isspace
*/

int my_isspace(char str)
{
    if (str == ' ' || str == '\t')
        return (1);
    return (0);
}