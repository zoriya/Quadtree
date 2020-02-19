##
## EPITECH PROJECT, 2019
## quadtree
## File description:
## Makefile
##

SRC = src/quadtree.c \
	src/qt_split.c \
	src/qt_collide.c \
	src/qt_destroy.c \
	src/qt_layer.c \
	src/qt_position_overlap.c \
	src/utility/calloc.c \
	src/array.c

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

all: $(NAME)

$(NAME): $(OBJ)
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