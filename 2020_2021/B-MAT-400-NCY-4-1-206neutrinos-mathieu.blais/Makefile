##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for python projects
##

EXEC = 206neutrinos
SRC = 206neutrinos.py

all:
	@cp $(SRC) $(EXEC)
	@chmod +x $(EXEC)
clean:
	@find . -type f -name '*~' -delete
fclean:	clean
	@$(RM) -f $(EXEC)
re: fclean all
.PHONY:	clean fclean re