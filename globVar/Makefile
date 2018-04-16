fin.out: a.o b.o
	gcc -Wall -o fin.out a.o b.o
	@echo "\n>>> Compile finished > fin.out\n"

a.o: main.h a.c
	gcc -Wall -c -o a.o a.c

b.o: main.h b.c
	gcc -Wall -c -o b.o b.c

clean:
	-rm *.o
	-rm *.out
