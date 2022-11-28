##
## EPITECH PROJECT, 2022
## print_readme
## File description:
## Makefile
##

DIRECTORY = src
FUNC = function

SRC = $(DIRECTORY)/print.c \
	$(DIRECTORY)/$(FUNC)/my_putstr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I include/
NAME = print_readme

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	@rm -rf $(OBJ) $(NAME)

fclean: clean
re: clean all

.PHONY: all clean fclean re
