##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
## $(wildcard *.c)

SRC	= $(wildcard *.c)

OBJ	= $(SRC:.c=.o)

NAME = print

LIB = -L ./lib/my -lmy

CFLAGS = -g -I /include/ -I /lib/my/

all:	$(OBJ)
	make -C ./lib/my
	$(CC) $(OBJ) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re: fclean all

.PHONY: all clean fclean re