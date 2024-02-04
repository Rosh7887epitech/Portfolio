##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/my_getnbr.c		\
		src/my_put_nbr.c 	\
		src/my_putstr.c		\
		src/my_strlen.c		\
		src/my_strdup.c		\
		src/hash.c			\
		src/new_hashtable.c	\
		src/dump.c			\
		src/my_itoa.c		\
		src/insert.c \
		src/my_strcmp.c \
		src/delete.c \
		src/search.c \
		src/del_hashtable.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	libhashtable.a

all: $(NAME)

$(NAME): $(OBJ)
	-ar rc -o $(NAME) $(OBJ) $(SFML)
	-rm $(OBJ)

unit_tests: fclean
	gcc -o unit_tests $(SRC) -g tests/unit_test.c -lcriterion --coverage
tests_run: unit_tests
	./unit_tests
coverage: tests_run
	gcovr --exclude tests/
	rm *.gc*
clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY:		fclean clean re all lib
