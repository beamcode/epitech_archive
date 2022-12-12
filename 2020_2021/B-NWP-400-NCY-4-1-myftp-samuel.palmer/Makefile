##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## C Makefile
##

EXEC = myftp

SRC	= $(wildcard src/*.c)
SRC	+= $(wildcard src/commands/*.c)

OBJ	= $(SRC:.c=.o)

CFLAGS += -I ./include
CFLAGS += -W -Wall -Wextra
LDFLAGS =
CC = clang

all: $(EXEC)
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $(EXEC) $(OBJ) $(CFLAGS)
clean:
	@$(RM) $(OBJ)
	@find . -type f -name "~*" -delete
	@find . -type f -name "*.gcda" -delete
	@find . -type f -name "*.gcno" -delete
	@find . -type d -name "*.dSYM" -delete
	@find . -type f -name ".DS_Store" -delete
fclean:	clean
	@$(RM) $(EXEC)
re: fclean all
.PHONY:	clean fclean re