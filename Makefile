##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c

TESTS_SRC	=	src/tests.c

TEST_NAME	=	unit_tests

OBJ	=	$(SRC:.c=.o)

NAME	=	pushswap

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) -o $(TEST_NAME) $(TESTS_SRC) -lcriterion

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY = all re clean fclean
