##
## EPITECH PROJECT, 2019
## Final Strumper
## File description:
## Final Stumper makefile
##

AR = ar

CC = gcc

SRC = $(filter-out main.c, $(wildcard *.c))
OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -Iinclude -L. -Wextra -Wformat

NAME_BIN = rush3

all: $(NAME) bin

$(NAME):$(OBJ)
		$(AR) rcs $(NAME) $(OBJ)
bin:
	$(CC) -o $(NAME_BIN) main.c $(CFLAGS) libmy.a

clean:
	$(RM) *.o /*gcda /*gcno

fclean: clean
		$(RM) *.gcda *.gcno
		$(RM) $(NAME_BIN)
		$(RM) $(NAME)
		$(RM) $(NAME_TEST)
		$(RM) *~

re : fclean all

.PHONY: bin clean fclean re
