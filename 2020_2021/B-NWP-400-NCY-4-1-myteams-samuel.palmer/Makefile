##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all: server client

server:
	@$(MAKE) -C server

client:
	@$(MAKE) -C cli

re:
	@$(MAKE) re -C cli
	@$(MAKE) re -C server

clean:
	@$(MAKE) clean -C cli
	@$(MAKE) clean -C server

fclean:
	@$(MAKE) fclean -C cli
	@$(MAKE) fclean -C server

.PHONY: all server client clean fclean re
