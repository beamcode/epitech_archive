##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

EXEC = menger
CC = clang
SRCS =  $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f

SOURCES_DIR = .
HEADERS_DIR = -I menger.h
LIBS_DIR = -L libraries

LDFLAGS =  $(LIBS_DIR)
CFLAGS = -ftest-coverage -O2 $(HEADERS_DIR)

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
		@find . -type f -name '.DS_Store' -delete
fclean: clean
		$(RM) $(EXEC)
re: fclean all
.PHONY: all clean fclean re delete archive num revert
