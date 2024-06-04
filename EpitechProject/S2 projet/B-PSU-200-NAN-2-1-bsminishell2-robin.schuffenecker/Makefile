##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	main.c

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	my_pipe

COMPIL 	=  -Wall -Wextra -Werror

CFLAGS += -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(COMPIL) -L./lib -lmy
	rm $(OBJ)

clean:
	rm -f $(OBJ)
	make -C ./lib clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib fclean

re: fclean all

.PHONY:		fclean clean re all lib
