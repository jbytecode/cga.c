example: example.c cga.c
	gcc -O3 -Wall -Wpedantic -o example example.c cga.c

clean:
	rm -f example
	rm -f libcga.so 

library:
	gcc -shared -o libcga.so -fPIC cga.c