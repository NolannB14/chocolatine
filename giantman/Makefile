##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/giantman.c	\
		src/display_results.c	\
		src/get_dictionnary.c	\
		src/get_encoded.c	\
		src/errors/check_errors.c	\
		../antman/src/get_file.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	giantman

CFLAGS	=	-Wall -Werror

CPPFLAGS	=	-I ../include

LDFLAGS	=	-L ../lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY	=	all re fclean clean
