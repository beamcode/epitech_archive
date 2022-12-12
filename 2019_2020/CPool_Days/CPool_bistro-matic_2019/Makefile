##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

OBJ	= $(SRC:.c=.o)

SRC	= $(wildcard *.c)

OBJ	= $(SRC:.c=.o)

NAME = calc

LIB = -L lib/my -lmy

INC	= -I ./include/

all:	$(OBJ)
	make -C ./lib/my
	$(CC) $(OBJ) -o $(NAME) $(INC) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f libmy.a
	make fclean -C ./lib/my

re: fclean all

.PHONY: all clean fclean re