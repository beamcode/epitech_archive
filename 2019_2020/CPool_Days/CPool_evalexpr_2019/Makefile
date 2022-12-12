##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

COMP	=	gcc -o

NAME	=	eval_expr

SRC	=	eval_expr.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I ./include

LIB	=	-L./lib/my/ -lmy

RM	=	rm -f

all:	$(OBJ)
	make -C ./lib/my/
	$(COMP) $(NAME) $(OBJ) $(LIB) $(INC)

clean:
	$(MAKE) -C ./lib/my/ clean

fclean: clean
	$(RM) eval_expr
	$(RM) ./lib/my/libmy.a
	$(RM) eval_expr.o

re: fclean all