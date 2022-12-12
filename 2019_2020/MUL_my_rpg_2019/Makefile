##
## EPITECH PROJECT, 2019
## bootstrap
## File description:
## Makefile
##

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = my_rpg

CFLAGS  = -W -Wextra -g -I ./include/ -lmy -L ./lib/my -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:    $(NAME)

lib_com:
	cd ./lib/my && $(MAKE)

$(NAME): $(OBJ) lib_com
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *~
	cd ./lib/my && $(MAKE)
	rm -f $(NAME)

re: fclean all
