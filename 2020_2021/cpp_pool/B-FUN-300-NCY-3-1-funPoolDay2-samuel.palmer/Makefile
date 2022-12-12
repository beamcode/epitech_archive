##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

EXEC = `test`
CC = ghc
SRCS = $(wildcard *.hs)
RM = rm -f

all: $(EXEC)
$(EXEC):
		$(CC) -c $(SRCS) $(EXEC)
clean:
		$(RM) $(EXEC)
		@find . -type f -name '*.hi' -delete

		@find . -type f -name '*~' -delete
		@find . -type f -name '#*#' -delete
		@find . -type f -name '*.o' -delete
		@find . -type f -name '*.gcda' -delete
		@find . -type f -name '*.gcno' -delete
		@find . -type f -name 'vgcore.*' -delete
		@find . -type f -name '.DS_Store' -delete
fclean: clean
		$(RM) $(EXEC)
re: fclean all
.PHONY: all clean fclean re
