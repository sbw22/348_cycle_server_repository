output: matrix_ops.o
	g++ matrix_ops.o -o output

matrix_ops.o: matrix_ops.cpp
	g++ -c matrix_ops.cpp

clean:
	rm *.o output

all: output
	./output
	make clean