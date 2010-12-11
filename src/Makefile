SERVER=jogo-cpp
CLIENT=Client
MANIF=manifest.txt
FLAGS=-Wall -ansi -pedantic


all: main $(CLIENT).jar $(MANIF) $(SERVER)

$(SERVER): $(SERVER).cpp
	g++ $(FLAGS) -lSDL_net $(SERVER).cpp -o $(SERVER)

$(CLIENT).jar: $(CLIENT).java $(MANIF)
	javac $(CLIENT).java
	jar cvfm $(CLIENT).jar $(MANIF) $(CLIENT).class
	chmod u+x $(CLIENT).jar

$(MANIF):
	echo Main-Class: $(CLIENT) > $(MANIF)
	echo >> $(MANIF)