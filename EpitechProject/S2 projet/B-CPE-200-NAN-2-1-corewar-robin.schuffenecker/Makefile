##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	main.c \
		src/parsing.c \
		src/read_cor_file.c \
		src/op.c \
		src/instruction.c \
		src/add_in_mem.c \
		put_fct/my_itoa.c \
		put_fct/my_put_nbr.c \
		src/game_loop.c \
		put_fct/my_getnbr.c \
		put_fct/my_putstr.c \
		put_fct/my_strcmp.c \
		put_fct/my_strdup.c \
		put_fct/my_strlen.c \

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	corewar

COMPIL 	=  -Wall -Wextra -Werror

COMPIL_TEST = tests/test_project.c -lcriterion --coverage -I./include

CFLAGS += -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMPIL) -g

test_uni : fclean
	gcc -o unit_tests $(SRC) $(COMPIL_TEST)

tests_run : test_uni
	./unit_tests

coverage : tests_run
	gcovr --exclude tests/
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

.PHONY:		fclean clean re all tests_run unit_tests coverage
