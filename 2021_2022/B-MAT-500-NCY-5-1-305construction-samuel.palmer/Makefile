##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for python projects
##

EXEC = 305construction
SRC = 305construction.py

all:
	@cp $(SRC) $(EXEC) 
	@chmod +x $(EXEC)
clean:
	@find . -type f -name '*~' -delete
fclean:	clean
	@$(RM) -f $(EXEC)
re: fclean all
.PHONY:	clean fclean re