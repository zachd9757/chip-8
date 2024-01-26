# run tests
run: test.c chip-8.c
	gcc -o chip test.c chip-8.c
	./chip

# debug
d: test.c chip-8.c
	gcc -g -o chip test.c chip-8.c
	gdb chip

clean:
	rm chip