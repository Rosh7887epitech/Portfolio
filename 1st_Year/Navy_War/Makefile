##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c 			\
		src/sig.c 			\
		src/hit_boat.c		\
		src/map_param.c 	\
		src/load_boat.c 	\
		src/verif_map.c     \
		src/game_fonc.c     \
		src/create_map.c 	\
		src/player_one.c 	\
		src/player_two.c 	\
		src/transmission.c 	\
		src/file_pos_read.c \
		src/hit_or_missed.c \

OBJ		=	$(SRC:%.c=%.o)

NAME 	=	Navy_War

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
