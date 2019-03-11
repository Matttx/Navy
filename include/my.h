/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h of My Navy
*/

#ifndef MY_H_
#define MY_H_

/* create_battle_field.c */
char **create_battle_field(char **field, char *buff);

/* create_battle_field_shoot.c */
char **create_battle_field_shoot(char **field);

/* print_game_board.c */
void print_game_board(char **field);

/* tools.c */
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *tab);

/* helper.c */
int helper(int ac, char **av);

/* j1 */
void who_sig_me_player_one(void);

/* j2 */
void who_sig_me_player_two(char **av);

/* game_player_one.c */
int game_player_one(char **field, char **field_shoot);

/* game_player_two.c */
int game_player_two(char **field, char **field_shoot);
char *order_give(void);
void hit_function(int signum);
int attack(char **field, char **field_shoot);

/* push_signal.c */
void push_signal(char *signal);

/* my_put_nbr_base.c */
char *convert_base_two(int nb);

/* binary_to_decimal.c */
int binary_to_decimal(char *tab);

/* my_strconcat.c */
char *my_strconcat(char a, char b);

/* my_revstr.c */
char *my_revstr(char *str);

/* read_file.c */
int read_file_player_one(char **argv, char *buff);
int read_file_player_two(char **argv, char *buff);

/* fill_battle_field.c */
void fill_position(char **field, char *buff);

/* check_boat.c */
int check_boat(char **field);
int check_loose(char **field);
int check_win(char **field_shoot);
int check_size(char **field);
int check_pos(char *buff);

/* my_raws.c */
int my_raws(char *tab);

/* my_putnbr.c */
int my_put_nbr(int nb);

/* get_line */
char *get_line(int fd);

/* check_order.c */
int check_order(char *str);

/* check_attack.c */
int check_attack(char **map, char *str);
int check_shoot(char **map, char *str);

#endif /* !MY_H_ */
