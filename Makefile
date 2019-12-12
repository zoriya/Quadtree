##
## EPITECH PROJECT, 2019
## quadtree
## File description:
## Makefile
##

SRC = src/quadtree.c \
	src/qt_split.c \
	src/utility/calloc.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = -I ./include

CFLAGS = $(INCLUDE) -Wall -Wextra -Wshadow

LDFLAGS = 

NAME = libquadtree.a

CC = gcc

AR = ar rc

all: build

build: $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

dbg: CFLAGS += -g
dbg: re

.PHONY: all build clean fclean