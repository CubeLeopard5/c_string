##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC			=	main.c

STRING_SRC	=	src/string_init.c		\
				src/string_destroy.c	\
				
TEST_SRC	=	tests/at.c				\
				tests/append.c			\
				tests/assign.c			\
				tests/c_str.c			\
				tests/compare.c			\
				tests/copy.c			\
				tests/empty.c			\
				tests/find.c			\
				tests/insert.c			\
				tests/size.c			\
				tests/ends_with.c		\
				tests/replace.c			\
				tests/reverse.c			\
				tests/split.c			\
				tests/starts_with.c		\
				tests/substring.c		\
				tests/trim.c			\

NAME		=	string

TEST_NAME 	=	string_tests

OBJS		=	$(SRC:.c=.o) $(STRING_SRC:.c=.o)

TEST_OBJS 	= $(STRING_SRC:.c=.o) $(TEST_SRC:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS = -Wall -Wextra -g3 -I ./include/

TEST_FLAGS = -I ./include/ -lcriterion;

STATIC_LIB_NAME	=    libstring.a

$(STATIC_LIB_NAME):    $(OBJ)
	ar rc  $(STATIC_LIB_NAME) $(OBJ)
	mv  $(STATIC_LIB_NAME) ../
	cp ./include/include.h ../../include/my_string.h

all:	$(NAME) $(TEST_NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

$(TEST_NAME):	$(TEST_OBJS)
	$(CC) -o $(TEST_NAME) $(TEST_OBJS) $(CFLAGS) $(TEST_FLAGS)

clean:
	rm -f $(OBJS) $(TEST_OBJS) ../$(STATIC_LIB_NAME)

fclean:	clean
	$(RM) $(NAME) $(TEST_NAME) ../$(STATIC_LIB_NAME)

re:		fclean all

.PHONY:	all clean fclean re