##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME = libmy_malloc.so

SRC = $(wildcard lib/*.c)
OBJ = $(SRC:.c=.o)

CFLAGS = -std=gnu11 -Wall -Wextra -g -fPIC -I ./include
LDFLAGS = -shared 
CC = gcc

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
.PHONY:	clean fclean re
