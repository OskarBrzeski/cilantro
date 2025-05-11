LIBS = -I./raylib/ -L./raylib/ -lraylib -lm

build: main.o title.o playfield.o utils.o ./src/globals.h
	mkdir -p ./bin
	cc -o ./bin/main main.o title.o playfield.o utils.o ${LIBS}

run: build
	./bin/main

main.o: ./src/main.c ./src/globals.h
	cc -c ./src/main.c ${LIBS}

title.o: ./src/title.c ./src/title.h ./src/globals.h
	cc -c ./src/title.c ${LIBS}

playfield.o: ./src/playfield.c ./src/playfield.h ./src/globals.h
	cc -c ./src/playfield.c ${LIBS}

utils.o: ./src/utils.c ./src/utils.h
	cc -c ./src/utils.c

clean:
	rm *.o
