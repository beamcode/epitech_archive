##
## EPITECH PROJECT, 2019
## libmy.a
## File description:
## makefile lib
##

SRCS = my_getnbr.c \
		my_putstr.c \
		my_putchar.c \
		my_getnbr.c \
		my_strlen.c \
		my_swap.c \
		my_isneg.c \
		my_put_nbr.c \
		my_atoi.c

NAME = libmy.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	cp libmy.a ../../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re