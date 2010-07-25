BDI=Bdi
MANIF=manifest.txt
FLAGS=-Wall -ansi -pedantic
FILES=Bdi.jar manifest.txt jogo fork

all: $(FILES)

Bdi.jar: $(BDI).java $(MANIF)
	javac $(BDI).java
	jar cvfm $(BDI).jar $(MANIF) *.class
	chmod u+x $(BDI).jar

manifest.txt:
	echo Main-Class: Bdi>$(MANIF)
	echo

jogo: jogo.cpp
	g++ $(FLAGS) jogo.cpp -o jogo

fork: fork.cpp
	g++ $(FLAGS) fork.cpp -o fork