COMP = g++ -std=c++11
CFLAG = -c -g

all: huffman

huffman: main.cpp Encoder.o
	$(COMP) -o huffman Encoder.o

Encoder.o: Encoder.cpp
	$(COMP) $(CFLAG) Encoder.cpp

clean:
	rm huffman *.o
