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

NAME		=	string

TEST_NAME 	=	string_tests

OBJS		=	$(SRC:.c=.o) $(STRING_SRC:.c=.o)

TEST_OBJS 	= $(STRING_SRC:.c=.o) $(TEST_SRC:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS = -Wall -Wextra -g3 -I ./include/

TEST_FLAGS = -I ./include/ -lcriterion;

all:	$(NAME) $(TEST_NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

$(TEST_NAME):	$(TEST_OBJS)
	$(CC) -o $(TEST_NAME) $(TEST_OBJS) $(CFLAGS) $(TEST_FLAGS)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean:	clean
	$(RM) $(NAME) $(TEST_NAME)

re:		fclean all

.PHONY:	all clean fclean re