all: game.cpp
	g++ -o sample2D game.cpp glad.c  -lGL  -ldl -lglfw -L/usr/local/lib 
