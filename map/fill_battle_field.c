/*
** EPITECH PROJECT, 2019
** fill_buff
** File description:
** fill_battle_field
*/

void fill_position(char **field, char *buff)
{
    char boat = 0;
    char letter_one = 0;
    char number_one = 0;
    char letter_two = 0;
    char number_two = 0;

    for (int row = 0; row < 4; row++) {
        boat = buff[row * 8];
        letter_one = buff[row * 8 + 2];
        number_one = buff[row * 8 + 3];
        letter_two = buff[row * 8 + 5];
        number_two = buff[row * 8 + 6];
        if (letter_one == letter_two)
            for (; number_one - '1' != number_two - '0'; number_one++)
                field[number_one - '1'][letter_one - 'A'] = boat;
        else
            for (; letter_one - 'A' != letter_two - 64; letter_one++)
                field[number_one - '1'][letter_one - 'A'] = boat;
    }
}