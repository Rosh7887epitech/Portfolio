##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	my_putchar.c					\
		my_put_nbr.c					\
		my_putstr.c					\
		my_strlen.c					\
		my_getnbr.c \
		my_strdup.c \
		my_itoa.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	-rm $(OBJ)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
