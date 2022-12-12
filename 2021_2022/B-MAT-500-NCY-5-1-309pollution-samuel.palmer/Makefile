##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for python projects
##

EXEC = 309pollution
SRC = 309pollution.py

all:
	@cp $(SRC) $(EXEC) 
	@chmod +x $(EXEC)
clean:
	@find . -type f -name '*~' -delete
fclean:	clean
	@$(RM) -f $(EXEC)
re: fclean all
.PHONY:	clean fclean re