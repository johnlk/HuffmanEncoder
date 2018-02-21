COMP = g++ -std=c++11
CFLAG = -c -g

all: huffman

huffman: main.cpp Encoder.o MinHeap.o TreeNode.o
	$(COMP) -o huffman Encoder.o MinHeap.o TreeNode.o

MinHeap.o: TreeNode.o MinHeap.cpp MinHeap.h 
	$(COMP) $(CFLAG) MinHeap.cpp

Encoder.o: Encoder.h Encoder.cpp
	$(COMP) $(CFLAG) Encoder.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(COMP) $(CFLAG) TreeNode.cpp

clean:
	rm huffman *.o
