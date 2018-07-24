CC =  g++
CCFLAGS = -g -Wall -Werror

complex: Complex.o ComplexTest.o 
	$(CC) -o complex $(CCFLAGS) Complex.o ComplexTest.o

Complex.o: Complex.cc complex.h
	$(CC) -c $(CCFLAGS) Complex.cc 

complexTest: ComplexTest.o 
	$(CC) -o complexTest $(CCFLAGS) ComplexTest.o 

ComplexTest.o: ComplexTest.cc complex.h
	$(CC) -c $(CCFLAGS) ComplexTest.cc 

clean:
	-rm *.o
