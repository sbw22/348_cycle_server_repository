

output: main.o isEven.o isOdd.o
	gcc main.o isEven.o isOdd.o -o output

main.o: main.c
	gcc -c main.c

isEven.o: isEven.c
	gcc -c isEven.c

isOdd.o: isOdd.c
	gcc -c isOdd.c

clean:
	rm *.o output