all: main

main: event-queue.c interop.c main.c
	gcc -g event-queue.c interop.c attributes.c main.c -DDEBUG=$(DEBUG) -o $@

clean:
	rm -v main || true
