##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	my_ls.c						\
		main.c						\
		add_list.c 					\
		get_elem_of_list.c 			\
		put_list.c 					\
		is_empty.c 					\
		len_list.c 					\
		my_rev_list.c 				\
		error.c 					\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) -I ./include -L./lib/my -lmy -Wall -Wextra -Werror
	-rm *.o

lib:
	-make -C lib/my

clean:
	-rm -f $(OBJ)
	-make -C ./lib/my clean

fclean: clean
	-rm -f $(NAME)
	-make -C ./lib/my fclean

re: fclean all

.PHONY:		fclean clean re all lib
