##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c 	\
		src/my_strlen.c 	\
		src/my_str_to_words_tok.c \
		src/stay_straight.c \
		src/stat_sim.c \
		src/info_func.c \
		src/move_funct.c \

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	ai

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
