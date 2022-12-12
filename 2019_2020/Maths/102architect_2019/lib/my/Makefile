##
## EPITECH PROJECT, 2019
## libmy.a
## File description:
## makefile lib
##

SRCS = $(wildcard *.c)

NAME = libmy.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -I .
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
##	mv libmy.a ../..

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re