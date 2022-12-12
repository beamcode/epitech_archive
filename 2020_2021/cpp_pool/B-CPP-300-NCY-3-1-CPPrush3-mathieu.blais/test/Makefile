##
## EPITECH PROJECT, 2020
## makefile
## File description:
## ok
##


SRC=			../backend/cpu.cpp\
				../backend/ram.cpp\
				../backend/info.cpp\
				../backend/hardware.cpp

SRC_UT_DIR=     $(realpath .)


SRC_UT= $(SRC_UT_DIR)/test_units.cpp	\

OBJ=            $(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

CXXFLAGS=         -Wall -Wextra --coverage -I.

LDFLAGS=        -lcriterion

NAME=           unit_tests

all:            $(NAME) run

$(NAME):        $(OBJ)
		@g++ -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

run:		$(NAME)
		@./unit_tests

clean:
		@rm -f $(OBJ)
		@find -type f -name '*gcda' -delete
		@find -type f -name '*gcno' -delete

fclean:         clean
		rm -f $(NAME)
		cd ../ && $(MAKE) fclean

re:             fclean all
