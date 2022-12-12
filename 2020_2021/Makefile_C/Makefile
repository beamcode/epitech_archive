##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## C Makefile
##

EXEC = a.out

SRC	= $(wildcard src/*.c)
OBJ	= $(SRC:.c=.o)

CFLAGS += -O2 -Wall -Wextra -I include
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
.PHONY:	all clean fclean re