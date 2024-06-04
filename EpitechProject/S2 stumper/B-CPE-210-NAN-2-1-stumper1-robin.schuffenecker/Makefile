##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \
		src/get_input.c \
		src/parse_args.c \
		src/find_word.c	\
		src/my_putstr.c	\
		src/my_putchar.c \
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	boggle

COMPIL 	+=  -Wall -Wextra -Werror

CFLAGS += -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(COMPIL)

clean:
	rm -rf $(OBJ)
	rm -rf *.gc*
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:		fclean clean re all tests_run
