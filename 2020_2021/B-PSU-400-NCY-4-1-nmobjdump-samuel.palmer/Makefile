##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## C Makefile
##

EXEC1 = my_nm
EXEC2 = my_objdump

SRC1	= $(wildcard nm/src/*.c)
SRC2	= $(wildcard obj/src/*.c)
OBJ1	= $(SRC1:.c=.o)

HEADERS_DIR1 = -I nm/include
HEADERS_DIR2 = -I obj/include

CFLAGS += -O2 -Wall -Wextra
CC = clang

all: objdump nm

nm: $(EXEC1)
$(EXEC1): $(OBJ1)
	$(CC) -o $(EXEC1) $(OBJ1) $(CFLAGS) $(HEADERS_DIR1)

objdump: $(EXEC2)
$(EXEC2): $(OBJ2)
	$(CC) -o $(EXEC2) $(OBJ2) $(CFLAGS) $(HEADERS_DIR2)

clean:
	@$(RM) $(OBJ1)
	@$(RM) $(OBJ2)
	@find . -type f -name "~*" -delete
	@find . -type f -name "*.gcda" -delete
	@find . -type f -name "*.gcno" -delete
	@find . -type d -name "*.dSYM" -delete
	@find . -type d -name ".vscode" -delete
	@find . -type f -name ".DS_Store" -delete
fclean:	clean
	@$(RM) -f $(EXEC1)
	@$(RM) -f $(EXEC2)
re: fclean all
.PHONY:	clean fclean re