##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC		=	string_init.c		\
			string_destroy.c	\

OBJ		=    $(SRC:.c=.o)

NAME	=    libstring.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc  $(NAME) $(OBJ)
	mv  $(NAME) ../
	cp string.h ../../include/
	$(MAKE) clean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
