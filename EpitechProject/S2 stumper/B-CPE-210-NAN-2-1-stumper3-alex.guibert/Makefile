##
## EPITECH PROJECT, 2022
## tictactoe
## File description:
## Stumper 3
##

SRC =	main.c\
        parsing.c \
	main_loop.c \
	init_grid.c \
	my_str_to_words_tok.c \
	check_end.c \
	my_strdup.c \

OBJ = 	$(SRC:.c=.o)

NAME =	tictactoe

all:	$(NAME) clean

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
