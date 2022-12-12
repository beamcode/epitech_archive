##
## EPITECH PROJECT, 2020
## test pour unitaires
## File description:
## aimé
##

## Sources à tester
SRC=           ../new.c \
				../player.c \
				../point.c \
				../vertex.c



## Tests unitaires
SRC_UT_DIR=     $(realpath .)
SRC_UT=         $(SRC_UT_DIR)/ex01_test.c

## Les OBJ de toutes les sources
OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

## Flags de compilation
CFLAGS=         -Wall -Wextra --coverage
LDFLAGS=        -lcriterion

NAME=           unit_tests

all:            $(NAME) run

## Rule de compilation
$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

## Rule de test
run:		#$(NAME)
		./unit_tests
		fclean

## Rule pour clean le repo
clean:
		@rm -f $(OBJ)
		@find . -type f -name '*.gcda' -delete
		@find . -type f -name '*.gcno' -delete
		@find ../ -type f -name '*.gcda' -delete
		@find ../ -type f -name '*.gcno' -delete
fclean: clean
		@rm -f $(NAME)

re:             fclean all
