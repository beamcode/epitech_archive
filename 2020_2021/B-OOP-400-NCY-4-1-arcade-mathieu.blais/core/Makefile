##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## C++ Makefile
##

EXEC = ../arcade

SRC	= $(wildcard *.cpp)
OBJ	= $(SRC:.cpp=.o)

HEADERS_DIR = -I
LDFLAGS +=
CXXFLAGS += -std=c++17 -g -O2 -Wall -Wextra -fPIC
CXX = g++

all: $(EXEC)
$(EXEC): $(OBJ)
	@$(CXX) $(LDFLAGS) $(OBJ) -o $(EXEC) -ldl

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) -f $(EXEC)

re:	fclean all
.PHONY: all clean fclean re
