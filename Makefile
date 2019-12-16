##
## EPITECH PROJECT, 2019
## quadtree
## File description:
## Makefile
##

SRC = src/quadtree.c \
	src/qt_split.c \
	src/qt_getcollide.c \
	src/qt_destroy.c \
	src/utility/calloc.c

OBJ = $(SRC:%.c=%.o)

TESTS = tests/test_collide.c \
	tests/test_add.c

COVERAGE = --coverage -lcriterion

INCLUDE = -I ./include

CFLAGS = $(INCLUDE) -Wall -Wextra -Wshadow

LDFLAGS = 

NAME = libquadtree.a

UT = ./ut

CC = gcc

AR = ar rc

all: build

build: $(OBJ)
	$(AR) $(NAME) $(OBJ)

tests_run:
	$(CC) -o $(UT) $(SRC) $(TESTS) $(COVERAGE) $(CFLAGS) -g
	$(UT)

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(UT)

re: fclean all

dbg: CFLAGS += -g
dbg: re

.PHONY: all build clean fclean