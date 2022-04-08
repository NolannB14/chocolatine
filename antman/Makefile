##
## EPITECH PROJECT, 2021
## Makefileanalysis, sorting and frequency tree
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/antman.c	\
		src/build_tree.c	\
		src/convert_binary.c	\
		src/get_char_code.c	\
		src/get_file.c	\
		src/get_occurrences.c	\
		src/list_features.c	\
		src/sort_list.c	\
		src/errors/check_errors.c

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

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
