##
## EPITECH PROJECT, 2025
## B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
## File description:
## Makefile
##

CXX = g++

CXXFLAGS = -Wall -Wextra -I./include

SRC =   src/AComponent.cpp 					\
		src/ACircuit.cpp 					\
		src/Factory.cpp 					\
		src/Parse.cpp 						\
		src/simpleComponent/OrComponent.cpp \
		src/simpleComponent/XorComponent.cpp 	\
		src/simpleComponent/NotComponent.cpp 	\
		src/simpleComponent/NorComponent.cpp 	\
		src/simpleComponent/AndComponent.cpp 	\
		src/simpleComponent/NandComponent.cpp 	\
		src/baseComponent/TrueComponent.cpp 	\
		src/baseComponent/ClockComponent.cpp 	\
		src/baseComponent/FalseComponent.cpp 	\
		src/baseComponent/InputComponent.cpp 	\
		src/baseComponent/OutputComponent.cpp 	\
		src/baseComponent/SplitterComponent.cpp \
		src/gateComponent/4081Component.cpp 	\
		src/gateComponent/4071Component.cpp 	\
		src/gateComponent/4011Component.cpp 	\
		src/gateComponent/4001Component.cpp 	\
		src/gateComponent/4030Component.cpp 	\
		src/gateComponent/4069Component.cpp 	\
		src/advancedComponent/FullAdder.cpp 	\
		src/advancedComponent/4008Component.cpp \

OBJ = $(SRC:.cpp=.o)
TARGET = nanotekspice

all: $(TARGET)

$(TARGET): $(OBJ) src/Main.o
	$(CXX) $(OBJ) -o $(TARGET) src/Main.o

tests_run: fclean
	g++ -o unit_tests $(SRC) tests/*.cpp -lcriterion --coverage $(CXXFLAGS)
	./unit_tests

coverage: fclean tests_run
	gcovr  --exclude tests/ --exclude include/

clean:
	rm -f $(OBJ)
	rm -f src/Main.o

fclean: clean
	rm -f $(TARGET)
	rm -f unit_tests
	rm -f *.gc*

re: fclean all

.PHONY: all clean fclean re tests_run coverage
