##
## EPITECH PROJECT, 2025
## ncurse
## File description:
## Makefile
##

NAME = raytracer

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC -lconfig++
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
SRC_DIR2 = RayTracer
BUILD_DIR = build

SRC = 	$(SRC_DIR)/utils/Point3D.cpp		\
		$(SRC_DIR)/utils/Vector3D.cpp		\
		$(SRC_DIR)/utils/Ray.cpp		    \
		$(SRC_DIR)/core/Factory.cpp		    	\
		$(SRC_DIR)/primitives/Cone/Cone.cpp		\
		$(SRC_DIR)/primitives/Cone/InfCone.cpp		\
		$(SRC_DIR)/primitives/Mobius/Mobius.cpp		\
		$(SRC_DIR)/primitives/Cube/Cube.cpp		\
		$(SRC_DIR)/primitives/Sphere/Sphere.cpp	\
		$(SRC_DIR)/primitives/Plane/Plane.cpp		\
		$(SRC_DIR)/primitives/Torus/Torus.cpp		\
		$(SRC_DIR)/primitives/Mesh/Mesh.cpp	    \
		$(SRC_DIR)/primitives/Cylinder/Cylinder.cpp	\
		$(SRC_DIR)/primitives/Cylinder/InfCylinder.cpp	\
		$(SRC_DIR)/primitives/Triangle/Triangle.cpp	\
		$(SRC_DIR)/textures/ChessBoard.cpp  \
		$(SRC_DIR)/textures/SimpleColor.cpp  \
		$(SRC_DIR)/textures/ImageTexture.cpp  \
		$(SRC_DIR)/core/Camera.cpp		    \
		$(SRC_DIR)/utils/Rectangle3D.cpp	\
		$(SRC_DIR)/utils/Matrix.cpp	        \
		$(SRC_DIR)/lights/DirectionalLight.cpp  \
		$(SRC_DIR)/lights/AmbientLight.cpp      \
		$(SRC_DIR)/lights/PointLight.cpp        \
		$(SRC_DIR)/core/Core.cpp		    	\
		$(SRC_DIR)/parser/Parser.cpp			\
		Main.cpp

OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

INCLUDES = -I.              \
	-I$(SRC_DIR)            \
	-I$(SRC_DIR)/utils      \
	-I$(SRC_DIR)/primitives \
	-I$(SRC_DIR)/primitives/Cone \
	-I$(SRC_DIR)/primitives/Sphere \
	-I$(SRC_DIR)/primitives/Cylinder \
	-I$(SRC_DIR)/primitives/Plane \
	-I$(SRC_DIR)/primitives/Triangle \
	-I$(SRC_DIR)/primitives/Torus \
	-I$(SRC_DIR)/primitives/Mobius \
	-I$(SRC_DIR)/primitives/Mesh \
	-I$(SRC_DIR)/primitives/Cube \
	-I$(SRC_DIR)/primitives/decorator \
	-I$(SRC_DIR)/textures	\
	-I$(SRC_DIR)/lights 	\
	-I$(SRC_DIR)/core       \
	-I$(SRC_DIR)/parser     \

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES) $(SFML_FLAGS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
