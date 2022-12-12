##
## EPITECH PROJECT, 2020
## 106bombyx.c
## File description:
## Makefile
##

SRC = 106bombyx.c \

OBJ = $(SRC:.c=.o)

NAME = 106bombyx

CFLAGS = -W -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
