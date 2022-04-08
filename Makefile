##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

TEST_NAME	=	unit_tests

all:	build

build:
	make -C lib/my
	make -C antman
	make -C giantman

# tests_run: LDFLAGS += --coverage -lcriterion
# tests_run:
# 	make -C lib/my
# 	make -C antman
# 	make -C giantman

# clean_tests:
# 	make fclean -C lib/my
# 	rm -f *.gc*
# 	rm -f $(TEST_NAME)

clean:
	make fclean -C lib/my
	make fclean -C antman
	make fclean -C giantman

fclean:	clean

re:	all

.PHONY	=	all re fclean clean build
