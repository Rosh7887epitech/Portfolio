##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	main.c \
		my_putstr.c \
		my_strlen.c \
		my_itao.c \
		my_put_nbr.c \
		my_putchar.c \
		my_strdup.c \
		my_atoi.c\
		verif.c\

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	cesar

COMPIL 	=  -Wall -Wextra -Werror

CFLAGS += -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMPIL) -g

unit_tests: fclean
	gcc -o unit_tests $(CFLAGS)
		-g tests/unit_test.c -lcriterion --coverage

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

.PHONY:		fclean clean re all tests_run unit_tests coverage
