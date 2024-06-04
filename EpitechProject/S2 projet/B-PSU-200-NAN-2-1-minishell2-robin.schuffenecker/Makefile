##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c 						\
		src/env/dup.c 					\
		src/env/env_set.c 				\
		src/env/env_call.c	 			\
		src/env/env_unset.c 			\
		src/env/env_error.c				\
		src/cd/cd_command.c 			\
		src/cd/cd_error.c				\
		src/command/launch.c 			\
		src/command/base_error.c		\
		src/command/clean_line.c 		\
		src/cd/cd_other_command.c 		\
		src/command/base_command.c 		\
		src/command/cond_command.c 		\
		src/command/separator.c 		\
		src/command/separator_cond.c	\
		src/command/redirection.c 		\
		src/command/redirection_cond.c 	\

LIB_SRC = 	lib/my_itoa.c 				\
			lib/my_putstr.c				\
			lib/my_strlen.c				\
			lib/my_getnbr.c 			\
			lib/my_strdup.c 			\
			lib/my_strcmp.c 			\
			lib/my_putchar.c			\
			lib/my_put_nbr.c			\
			lib/my_strncpy.c 			\
			lib/my_str_to_words_array.c	\
			lib/my_str_to_words_tok.c 	\
			src/command/clean_line.c 	\
			src/command/base_command.c 	\
			src/command/base_error.c	\

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	mysh

COMPIL 	=  -Wall -Wextra -Werror

CFLAGS += -I./include -g

LIB_PATH = ./lib
LIB_NAME = my
LIB = -L$(LIB_PATH) -l$(LIB_NAME)

all: $(NAME)

$(NAME): lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMPIL) $(LIB) -g

lib:
	make -C $(LIB_PATH)

unit_tests: fclean
	gcc -o unit_tests $(LIB_SRC) $(CFLAGS)
		-g tests/unit_test.c -lcriterion --coverage

tests_run: unit_tests
	./unit_tests

coverage: tests_run
	gcovr --exclude tests/
	rm *.gc*

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY:		fclean clean re all lib tests_run unit_tests coverage
