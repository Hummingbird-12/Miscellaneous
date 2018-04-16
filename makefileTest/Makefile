# all: test
test: a.o b.o c.o
	gcc -o test a.o b.o c.o
a.o: a.h b.h a.c
	gcc -c -o a.o a.c
b.o: a.h b.h c.h b.c
	gcc -c -o b.o b.c
c.o: b.h c.h c.c
	gcc -c -o c.o c.c

clean:
	rm *.o
	rm test
