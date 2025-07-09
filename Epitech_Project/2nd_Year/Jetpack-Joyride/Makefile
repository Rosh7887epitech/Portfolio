##
## EPITECH PROJECT, 2025
## B-NWP-400-NAN-4-1-jetpack-romain.berard
## File description:
## Makefile
##

EXECUTABLE = jetpack_server

SRC = 	lib/my_strcat.c 			\
		lib/my_strcpy.c 			\
		lib/my_strlen.c 			\
		lib/my_strdup.c 			\
		lib/my_strcmp.c 			\
		src/server/server.c 		\
		src/server/read_socket.c 	\
		src/server/str_clean.c 		\
		src/server/action.c 		\
		src/server/map.c 			\
		src/server/send_response.c 	\
		src/server/collision.c 		\

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -I./include


all: server client

client:
	$(MAKE) -C src/client/

re: fclean all

lib: $(OBJ)
	ar rc libmy.a $(OBJ)

server: lib src/server/main.o
	gcc -o $(EXECUTABLE) src/server/main.o -L. -lmy $(CFLAGS)

clean:
	$(MAKE) -C src/client/ clean
	rm -f $(OBJ)
	rm -f src/server/main.o

fclean: clean
	$(MAKE) -C src/client/ fclean
	rm -f $(EXECUTABLE)
	rm -f libmy.a
	rm -f *.gc*
	rm -f unit_tests


.PHONY: clean fclean re server lib all tests_run coverage client
