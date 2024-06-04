##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC		=	main.c

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	a.out

CFLAGS 	+=  -Wall -Wextra -Werror $(INCLUDE)

INCLUDE = -I ./include

LIB 	= -L./lib -lmy

.PHONY: fclean clean re all $(NAME) $(LIB)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
	rm $(OBJ)


clean:
	rm -f $(OBJ)
	make -C ./lib clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib fclean

re: fclean all
