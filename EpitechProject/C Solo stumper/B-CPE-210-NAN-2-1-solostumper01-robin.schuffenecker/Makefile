##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	a.out

all: $(NAME)

$(NAME): $(OBJ)
	-gcc -o $(NAME) $(OBJ) $(SFML)
	-rm $(OBJ)
clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY:		fclean clean re all lib
