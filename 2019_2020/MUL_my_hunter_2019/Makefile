##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
## $(wildcard *.c)

OBJ	= $(SRC:.c=.o)
SRC	= $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
NAME = my_hunter
LIB = -L ./lib/my -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-system
INC	= -I /include/my.h -I /lib/my/my_lib.h
CFLAGS = -g
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