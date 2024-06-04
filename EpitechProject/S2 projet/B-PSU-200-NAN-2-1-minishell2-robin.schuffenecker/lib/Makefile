##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	my_itoa.c 				\
		my_putstr.c				\
		my_strlen.c				\
		my_getnbr.c 			\
		my_strdup.c 			\
		my_strcmp.c 			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_strncpy.c 			\
		my_str_to_words_array.c	\
		my_str_to_words_tok.c 	\


OBJ	=	$(SRC:%.c=%.o)

NAME	=	libmy.a

CFLAGS = -I../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re:	fclean all

.PHONY: all clean re fclean
