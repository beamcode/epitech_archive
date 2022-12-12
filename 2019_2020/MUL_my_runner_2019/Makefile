##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	= $(wildcard src/*.c)
OBJ	= $(SRC:.c=.o)
NAME    = my_runner
LIB     = -L ./src/lib -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-system
INC	= -I include -I ./src/lib/my_lib.h 
CFLAGS  = -g

all: $(NAME)
$(NAME): $(OBJ)
	make -C ./src/lib
	$(CC) $(OBJ) -o $(NAME) $(INC) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C ./src/lib

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f src/libmy.a
	make fclean -C ./src/lib

re: fclean all
.PHONY: all clean fclean re
