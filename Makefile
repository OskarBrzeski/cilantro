LIBS = -I./raylib/ -L./raylib/ -lraylib -lm

build: main.o title.o
	mkdir -p ./bin
	cc -o ./bin/main main.o title.o ${LIBS}

run: build
	./bin/main

main.o: ./src/main.c
	cc -c ./src/main.c ${LIBS}

title.o: ./src/title.c ./src/title.h
	cc -c ./src/title.c ${LIBS}

clean:
	rm *.o
