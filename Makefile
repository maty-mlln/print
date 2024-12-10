##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

MAKEFLAGS += -B -s
CFLAGS = -W -Wall -Wextra -I./include

SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)

NAME = ../libutils.a

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(CFLAGS)
	ar -rc $(NAME) $(OBJ)
	$(MAKE) clean

clean:
	find . -name "*.gc*" -delete
	find . -name "*.o" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all
