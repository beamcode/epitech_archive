##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

EXEC = fakeProj
CC = clang
SRCS =  \
		./main.c \
		./calc.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

SOURCES_DIR = .
PROJECT_DIR = fakeProj1
LIBS_DIR = -L librarys
HEADERS_DIR = -I include
BCK_DIR = backup

LDFLAGS =  $(LIBS_DIR)
CFLAGS = -ftest-coverage -O2 $(HEADERS_DIR)

ZIP = tar
UNZIP = tar
ZIPFLAGS = -cvvf
UNZIPFLAGS = -xvf
VERSION = $$(cat $(BCK_DIR)/.version)


all: $(EXEC)
$(EXEC): $(OBJS)
		$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
clean:
		$(RM) $(OBJS)
		@find . -type f -name '*~' -delete
		@find . -type f -name '#*#' -delete
		@find . -type f -name '*.o' -delete
		@find . -type f -name '*.gcda' -delete
		@find . -type f -name '*.gcno' -delete
		@find . -type f -name 'vgcore.*' -delete
fclean: clean
		$(RM) $(EXEC)
re: fclean all
archive:
		mkdir -p $(BCK_DIR)
		@echo $$(( $(VERSION) + 1)) > ./$(BCK_DIR)/.version
		@$(ZIP) $(ZIPFLAGS) $(BCK_DIR)/$(EXEC)_$(VERSION).$(ZIP) $(SRCS)
revert:
		$(UNZIP) $(UNZIPFLAGS) $(BCK_DIR)/$(EXEC)_$(VERSION).$(ZIP)
		@echo $$(( $(VERSION) - 1)) > ./$(BCK_DIR)/.version
num:
		@echo $(VERSION)
delete:
		@rm -rf $(BCK_DIR)/$(EXEC)_$(VERSION).$(ZIP)
		@echo $$(( $(VERSION) - 1)) > ./$(BCK_DIR)/.version
.PHONY: all clean fclean re delete archive num revert
