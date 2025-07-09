##
## EPITECH PROJECT, 2025
## B-NWP-400-NAN-4-1-jetpack-romain.berard
## File description:
## Makefile
##

EXECUTABLE = ../../jetpack_client

SRC = 	Client.cpp 		\
		Graphics.cpp 	\


OBJ = $(SRC:.cpp=.o)

CXXFLAGS += -Wall -Wextra -lsfml-graphics \
			-lsfml-window -lsfml-system -lsfml-audio

CC = g++

all: client

Main.o: Main.cpp
	$(CC) -c Main.cpp $(CXXFLAGS)

client: $(OBJ) Main.o
	$(CC) -o $(EXECUTABLE) $(OBJ) Main.o $(CXXFLAGS)

clean:
	rm -f $(OBJ)
	rm -f Main.o

fclean: clean
	rm -f $(EXECUTABLE)
