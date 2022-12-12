##
## EPITECH PROJECT, 2021
## makefilerush3
## File description:
## cppool
##

SRC=			SFML/window.cpp \
				SFML/Button.cpp \
				SFML/getEvent.cpp \
				SFML/RectangleShape.cpp \
				SFML/Sprite.cpp \
				SFML/Text.cpp \
				SFML/graphic_loop.cpp\
				backend/cpu.cpp\
				backend/ram.cpp\
				backend/info.cpp\
				backend/hardware.cpp\
				ncurses/ncurses.cpp\
				main.cpp\


CFLAGS=	-std=c++17 -Wall -Wextra -g

NAME=	MyGKrellm

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -g -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lcurses

all:		$(NAME)

clean:
				@find -type f -name '*~' -delete
				@find -type f -name '#*#' -delete
				@find -type f -name '*.o' -delete
				@find -type f -name '*gcda' -delete
				@find -type f -name '*gcno' -delete
fclean:			clean
				rm -f $(NAME)
re:				fclean all

.PHONY:			clean fclean re
