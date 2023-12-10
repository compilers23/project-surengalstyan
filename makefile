all: compiler main test

compiler: compiler.c
	gcc -o compiler compiler.c

input.s: test.txt compiler
	./compiler test.txt input.s

main.o: input.s
	as -o main.o input.s

print.o: print.s
	as -o print.o print.s

main: main.o print.o
	gcc -o main main.o print.o -lc

test.o: input.s
	as -o test.o input.s

test: test.o print.o
	gcc -o test test.o print.o -lc

clean:
	rm -f main test main.o test.o print.o compiler input.s
