LIBS = -I./raylib/ -L./raylib/ -lraylib -lm

build: main.o
	mkdir -p ./bin
	cc -o ./bin/main main.o ${LIBS}

run: build
	./bin/main

main.o: ./src/main.c
	cc -c ./src/main.c ${LIBS}

clean:
	rm *.o
