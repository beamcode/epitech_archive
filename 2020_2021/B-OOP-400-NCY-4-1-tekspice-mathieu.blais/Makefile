##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## C++ Makefile
##

EXEC = nanotekspice

SRC	= $(wildcard src/*.cpp)
OBJ	= $(SRC:.cpp=.o)

CXXFLAGS += -std=c++17 -g -O2 -I include -Wall -Wextra
CXX = g++

all: $(EXEC)
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(CXXFLAGS)

clean:
	@$(RM) $(OBJ)
	@$(RM) -f *~
	@$(RM) -f .DS_Store
	@$(RM) -rf vgcore.*
	@$(RM) -rf *.gcda
	@$(RM) -rf *.gcno
	@$(RM) -rf *.dSYM

fclean:	clean
	@$(RM) -f $(EXEC)

re:	fclean all
.PHONY: all clean fclean re
