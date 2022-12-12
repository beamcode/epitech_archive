##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Cpp Makefile
##

EXEC1 = ../lib/arcade_nibbler.so
EXEC2 = ../lib/arcade_solarfox.so
EXEC3 = ../lib/arcade_menu.so

#SOURCES
SRC1 = $(wildcard nibbler/*.cpp)
SRC2 = $(wildcard solarfox/*.cpp)
SRC3 = $(wildcard menu/*.cpp)

#OBJECTS
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)

HEADERS_DIR = -I
LDFLAGS = -shared
CXXFLAGS += -std=c++17 -g -O2 -Wall -Wextra -fPIC
CXX = g++

all: nibbler solarfox menu

nibbler: $(EXEC1)
$(EXEC1): $(OBJ1)
	@$(CXX) $(LDFLAGS) $(OBJ1) -o $(EXEC1)

solarfox: $(EXEC2)
$(EXEC2): $(OBJ2)
	@$(CXX) $(LDFLAGS) $(OBJ2) -o $(EXEC2)

menu: $(EXEC3)
$(EXEC3): $(OBJ3)
	@$(CXX) $(LDFLAGS) $(OBJ3) -o $(EXEC3)

clean:
	@$(RM) $(OBJ1)
	@$(RM) $(OBJ2)
	@$(RM) $(OBJ3)

fclean:	clean
	@$(RM) -f $(EXEC1)
	@$(RM) -f $(EXEC2)
	@$(RM) -f $(EXEC3)

re: fclean all
.PHONY:	all clean fclean re nibbler solarfox menu
