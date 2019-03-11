/*
** EPITECH PROJECT, 2018
** binary_to_decimal.c
** File description:
** No description
*/

int binary_to_decimal(char *tab)
{
    int result = 0;
    int pow = 1;

    for (int i = 7; i >= 0; i--) {
        if (tab[i] == '1')
            result += pow;
        pow *= 2;
    }
    return (result);
}