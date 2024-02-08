run: main.c chip-8.c
	gcc -o chip main.c chip-8.c
	./chip

# run tests
test: test.c chip-8.c
	gcc -o chip test.c chip-8.c
	./test-chip

# debug
d: test.c chip-8.c
	gcc -g -o chip test.c chip-8.c
	gdb chip

clean:
	rm chip test-chip *.out