##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	     = $(wildcard *.c)
OBJ	     = $(SRC:.c=.o)
NAME     = test
LIB      = -L ./lib/my -lmy
INC	     = -I /include/my.h -I /lib/my/my_lib.h
CFLAGS   = -g

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./lib/my
		$(CC) $(OBJ) -o $(NAME) $(INC) $(LIB)
clean:
	rm -f $(OBJ)
	make clean -C ./lib/my
fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C ./lib/my
re: fclean all
.PHONY: all clean fclean re