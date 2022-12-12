##
## EPITECH 2019
## 
## File description:
## 
##

SRC	= $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
NAME = geekNameFormatter
CFLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
re: fclean all
.PHONY: all clean fclean re