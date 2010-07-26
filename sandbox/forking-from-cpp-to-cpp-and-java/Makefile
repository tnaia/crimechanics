BDI=Bdi
MANIF=manifest.txt
FLAGS=-Wall -ansi -pedantic
FILES=$(BDI).jar $(MANIF) jogo fork

all: $(FILES)

$(BDI).jar: $(BDI).java $(MANIF)
	javac $(BDI).java
	jar cvfm $(BDI).jar $(MANIF) *.class
	chmod u+x $(BDI).jar

$(MANIF):
	echo Main-Class: $(BDI) > $(MANIF)
	echo

jogo: jogo.cpp
	g++ $(FLAGS) jogo.cpp -o jogo

fork: fork.cpp
	g++ $(FLAGS) fork.cpp -o fork