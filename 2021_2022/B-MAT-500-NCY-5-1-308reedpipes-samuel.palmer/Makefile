##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for python projects
##

EXEC = 308reedpipes
SRC = 308reedpipes.py

all:
	@cp $(SRC) $(EXEC) 
	@chmod +x $(EXEC)
clean:
	@find . -type f -name '*~' -delete
fclean:	clean
	@$(RM) -f $(EXEC)
re: fclean all
.PHONY:	clean fclean re