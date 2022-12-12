## 
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC    = $(wildcard *.c)
OBJ    = $(SRC:.c=.o)
NAME   = baggle
INC    = -I my.h
CFLAGS = -g
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INC)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
re: fclean all
.PHONY: all clean fclean re
