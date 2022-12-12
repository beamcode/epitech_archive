##
## EPITECH PROJECT, 2019
## makefile
## File description:
## rush2
##

CC	=	ar rc

NAME	=	libmy.a

SRC	=	*.c

OBJ	=	*.o

all:	gcc compilation move

gcc:
	gcc -c $(SRC)

compilation:
	ar rc $(NAME) $(OBJ)

move:
	cp $(NAME) ./../

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	re all clean fclean