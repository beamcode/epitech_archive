##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to call other makefiles
##

all:
	@echo "\n[Makefile] compiling core"
	@$(MAKE) -C core
	@echo "\n[Makefile] compiling games"
	@$(MAKE) -C games
	@echo "\n[Makefile] compiling graphicals"
	@$(MAKE) -C graphicals

re:
	@echo "\n[Makefile] compiling core"
	@$(MAKE) re -C core
	@echo "\n[Makefile] compiling games"
	@$(MAKE) re -C games
	@echo "\n[Makefile] compiling graphicals"
	@$(MAKE) re -C graphicals

clean:
	@echo "[Makefile] all temp files removed"
	@$(MAKE) clean -C core
	@$(MAKE) clean -C games
	@$(MAKE) clean -C graphicals

fclean:
	@echo "[Makefile] all temp files and binaries removed"
	@$(MAKE) fclean -C core
	@$(MAKE) fclean -C games
	@$(MAKE) fclean -C graphicals

core:
	@echo "\n[Makefile] compiling core"
	@$(MAKE) -C core

games:
	@echo "\n[Makefile] compiling games"
	@$(MAKE) -C games

graphicals:
	@echo "\n[Makefile] compiling graphicals"
	@$(MAKE) -C graphicals

.PHONY: all clean fclean re core games graphicals
