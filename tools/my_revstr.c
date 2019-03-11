/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** tak03
*/

char *my_revstr(char *str)
{
    int i = 0;
    int a = 0;
    char c;
    int b = 0;

    while (str[i] != '\0') {
        i++;
    }
    b = i - 1;
    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a++;
        b--;
    }
    return (str);
}
