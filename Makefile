COMP = g++ -std=c++11
CFLAG = -c -g

all: huffman

huffman: main.cpp Encoder.o MinHeap.o TreeNode.o HuffTree.o
	$(COMP) -o huffman Encoder.o MinHeap.o TreeNode.o HuffTree.o main.cpp

MinHeap.o: TreeNode.o Encoder.o MinHeap.cpp MinHeap.h 
	$(COMP) $(CFLAG) MinHeap.cpp

Encoder.o: TreeNode.o Encoder.h Encoder.cpp
	$(COMP) $(CFLAG) Encoder.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(COMP) $(CFLAG) TreeNode.cpp

HuffTree.o: TreeNode.o MinHeap.o HuffTree.h HuffTree.cpp
	$(COMP) $(CFLAG) HuffTree.cpp

clean:
	rm huffman *.o
