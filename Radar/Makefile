##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \
		src/draw.c \
		src/add_list.c \
		src/colision.c \
		src/shape_init.c \
		src/close_windows.c \
		src/plane.c \
		src/background.c \
		src/tower.c \
		src/my_strdup.c \
		src/pos_search.c \
		src/array_file.c \
		src/disp_timer.c \
		src/game_lauch.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_radar

COMPIL 	= -I./include -L./lib/my -lmy -Wall -Wextra -Werror

SFML 	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all: $(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) $(COMPIL) $(SFML)
	-rm $(OBJ)

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
