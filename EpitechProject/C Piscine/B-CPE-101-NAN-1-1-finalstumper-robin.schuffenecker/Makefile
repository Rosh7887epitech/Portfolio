##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	lib/my/my_putchar.c			\
		lib/my/my_put_nbr.c			\
		lib/my/my_putstr.c			\
		lib/my/my_strlen.c			\
		lib/my/rush3.c				\
		lib/my/get_string.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	-cp $(NAME) lib/
	-mkdir include
	-cp lib/my/my.h include/
clean:
	-rm -f $(OBJ)
fclean: clean
	-rm -f $(NAME)
	-rm -r include/
	-rm -f libmy.a
	-rm -f lib/libmy.a

re:	fclean all

auteur:
	echo $(USER) > auteur
