##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Cpp Makefile
##

EXEC1 = ../lib/arcade_ncurses.so
EXEC2 = ../lib/arcade_sdl2.so
EXEC3 = ../lib/arcade_sfml.so

#SOURCES
SRC1 = $(wildcard ncurses/*.cpp)
SRC2 = $(wildcard sdl2/*.cpp)
SRC3 = $(wildcard sfml/*.cpp)

#OBJECTS
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)

HEADERS_DIR = -I
LDFLAGS = -shared
CXXFLAGS += -std=c++17 -g -O2 -Wall -Wextra -fPIC
CXX = g++

all: ncurses sdl2 sfml

ncurses: $(EXEC1)
$(EXEC1): $(OBJ1)
	@$(CXX) $(LDFLAGS) $(OBJ1) -o $(EXEC1) -lncurses

sdl2: $(EXEC2)
$(EXEC2): $(OBJ2)
	@$(CXX) $(LDFLAGS) $(OBJ2) -o $(EXEC2) -lSDL2main -lSDL2_ttf -lSDL2

sfml: $(EXEC3)
$(EXEC3): $(OBJ3)
	@$(CXX) $(LDFLAGS) $(OBJ3) -o $(EXEC3) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	@$(RM) $(OBJ1)
	@$(RM) $(OBJ2)
	@$(RM) $(OBJ3)

fclean:	clean
	@$(RM) -f $(EXEC1)
	@$(RM) -f $(EXEC2)
	@$(RM) -f $(EXEC3)

re: fclean all
.PHONY:	all clean fclean re sfml sdl2 ncurses
