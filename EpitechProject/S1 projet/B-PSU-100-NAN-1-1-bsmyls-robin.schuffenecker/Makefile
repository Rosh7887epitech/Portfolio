##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c					\
		my_bsls.c					\
		main.c						\

OBJ	=	$(SRC:.c=.o)

NAME	=	info_file

all:	$(NAME)

$(NAME):	$(OBJ)
	-gcc -o $(NAME) $(OBJ) -I./include

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all
