##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	lib/my/my_putchar.c				\
		lib/my/my_printf.c				\
		lib/my/my_put_nbr.c				\
		lib/my/my_putstr.c				\
		lib/my/my_strlen.c				\
		lib/my/my_str_isalpha.c			\
		lib/my/my_strncpy.c 			\
		lib/my/my_count_nbr.c			\
		lib/my/my_put_unsigned_nbr.c	\
		lib/my/put_c.c					\
		lib/my/put_i_d.c				\
		lib/my/put_s.c					\
		lib/my/put_u.c					\
		lib/my/put_pourcent.c			\
		lib/my/put_hexa.c				\
		lib/my/put_octal.c				\
		lib/my/my_getnbr.c				\
		lib/my/convertion.c				\
		lib/my/put_p.c					\
		lib/my/put_f.c					\
		lib/my/my_put_float_nbr.c		\
		lib/my/put_e.c					\
		lib/my/put_hexa_upper.c			\
		lib/my/hashtag.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	-cp $(NAME) lib/
	-mkdir include
	-cp lib/my/my.h include/
run:
	-gcc main.c -L -lmy
unit_tests:
	-gcc -o unit_tests tests/test_my_printf.c $(SRC) --coverage -lcriterion
clean:
	-rm -f $(OBJ)
fclean: clean
	-rm -f $(NAME)
	-rm -r include/
	-rm -f libmy.a
	-rm -f lib/libmy.a
test_run:
	-./unit_tests
re: fclean all
