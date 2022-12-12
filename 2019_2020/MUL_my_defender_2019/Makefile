##
## EPITECH PROJECT, 2020
## my_defender_2019
## File description:
## Makefile
##

SRC	=	main.c \
		display_game.c \
		create_menu.c \
		create_game.c \
		check_position.c \
		init_game.c \
		init_game_button.c \
		create_pause.c \
		init_pause_button.c \
		button.c \
		destroy_game.c \

OBJ	= 	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS = -W -Wall -Wextra -I./include -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
