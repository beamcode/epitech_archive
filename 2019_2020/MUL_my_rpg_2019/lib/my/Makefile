##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile lib
##

CC = gcc

SRC =	 $(wildcard *.c)

OBJ = 	$(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f *~
