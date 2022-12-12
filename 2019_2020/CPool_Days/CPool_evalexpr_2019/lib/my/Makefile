##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CMP	= gcc -c

NAME = libmy.a

SRC	= $(wildcard *.c)

OBJ	= $(SRC:.c=.o)

RM = rm -f

AR = ar rc

all: $(NAME)

$(NAME):	$(OBJ)
	$(CMP) $(SRC)
	$(AR) $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)