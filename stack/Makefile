EXE=test 
CC=g++
CCFLAGS=-std=c++11
DEBUG=-g

all: $(EXE)

test: test.cxx
	$(CC) $(CCFLAGS) $(DEBUG) -o $@ $^

clean:
	rm -rf *.o *.gch $(EXE)


