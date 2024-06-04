##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	my_putchar.c					\
		my_isneg.c					\
		my_strcmp.c					\
		my_put_nbr.c					\
		my_putstr.c					\
		my_strlen.c					\
		my_getnbr.c					\
		my_strcpy.c 					\
		my_strcat.c 					\
		my_put_float_nbr.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	-rm -f $(NAME)

fclean: clean
	-rm $(OBJ)

re:	fclean all

auteur:
	echo $(USER) > auteur
