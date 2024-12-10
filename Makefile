##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

MAKEFLAGS += -B -s
CFLAGS = -W -Wall -Wextra -Werror -I./include

SRC = $(shell find src -name "*.c")

NAME = print

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)
	$(MAKE) clean

clean:
	find . -name "*.gc*" -delete
	find . -name "*.o" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	$(CC) -g3 -o $(NAME) $(SRC) $(CFLAGS)
	clear
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) 2> valgrind.log
	cat valgrind.log && rm valgrind.log
	$(MAKE) fclean
