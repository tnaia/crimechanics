BDI=Bdi
MANIF=manifest.txt
FLAGS=-Wall -ansi -pedantic
FILES=$(BDI).jar $(MANIF) jogo fork
TEXT=Main-Class: $(BDI) 
all: $(FILES)

$(BDI).jar: $(BDI).java $(MANIF)
	javac $(BDI).java
	jar cvfm $(BDI).jar $(MANIF) $(BDI).class
#	jar cf $(BDI).jar $(BDI).class
	chmod u+x $(BDI).jar

$(MANIF):
	touch $(MANIF)
	echo $(TEXT) 1> $(MANIF)
	echo 1>> $(MANIF)

jogo: jogo.cpp
	g++ $(FLAGS) jogo.cpp -o jogo

fork: fork.cpp
	g++ $(FLAGS) fork.cpp -o fork