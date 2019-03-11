##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for PSU_navy_2018
##

NAME		=		navy

CC				=		gcc

RM				=		rm -f

SRC             =		main.c                  				\
						helper.c								\
						tools/tools.c							\
						tools/my_revstr.c						\
						tools/binary_to_decimal.c				\
						tools/my_strconcat.c					\
						tools/my_raws.c							\
						tools/my_put_nbr.c						\
						tools/my_put_nbr_base.c					\
						tools/get_line.c						\
						tools/check_order.c 					\
						map/create_battle_field.c				\
						map/create_battle_field_shoot.c			\
						map/print_game_board.c					\
						map/read_file.c 						\
						map/fill_battle_field.c					\
						map/check_boat.c						\
						players/player_one.c					\
						players/player_two.c					\
						game/game_player_one.c					\
						game/push_signal.c						\
						game/game_player_two.c					\
						game/order.c							\
						game/check_attack.c 					\

OBJ             =		$(SRC:.c=.o)

CFLAGS          +=		-I "./include/" -g3
CFLAGS			+=		-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean