all: jogo

jogo: jogo-cpp jogo-java

jogo-cpp: jogo.cpp

Renderer.o: Renderer.cpp Renderer.hpp
	g++ -Wall -ansi -O2 -pedantic -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer Renderer.cpp -c

SDLManager.o: SDLManager.cpp SDLManager.hpp
	g++ -Wall -ansi -O2 -pedantic -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer SDLManager.cpp -c

teste-renderer: Renderer.o SDLManager.o main-Renderer.cpp
	g++ -Wall -ansi -O2 -pedantic -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer Renderer.o main-Renderer.cpp -o Main