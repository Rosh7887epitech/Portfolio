##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	main.c 	\
		my_itoa.c \
		my_strlen.c \

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	chocolatine

COMPIL 	=  -Wall -Wextra -Werror

CFLAGS += -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMPIL)

unit_tests: fclean
	gcc -o unit_tests $(SRC) $(CFLAGS) -g tests/unit.c -lcriterion --coverage

tests_run: unit_tests
	./unit_tests

coverage: tests_run
	gcovr --exclude tests/
	rm *.gc*

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

.PHONY:		fclean clean re all lib tests_run unit_tests coverage
