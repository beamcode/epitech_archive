##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

EXEC = 	pushswap_checker
SRC	= 	$(wildcard *.hs)
RM = 	rm -f

all:
		ghc -c -O $(SRC)
		ghc -o $(EXEC) *.o

clean:
		$(RM) *.o
		@find . -type f -name '*.hi' -delete

fclean: clean
		$(RM) $(EXEC)

re: fclean all
.PHONY: all clean fclean