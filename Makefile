COMP = g++ -std=c++11
CFLAG = -c -g

all: huffman

huffman: main.cpp HuffTree.o MinHeap.o Encoder.o TreeNode.o
	$(COMP) -o huffman HuffTree.o MinHeap.o Encoder.o TreeNode.o main.cpp

MinHeap.o: TreeNode.o Encoder.o MinHeap.cpp MinHeap.h 
	$(COMP) $(CFLAG) MinHeap.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(COMP) $(CFLAG) TreeNode.cpp

Encoder.o: TreeNode.o Encoder.h Encoder.cpp
	$(COMP) $(CFLAG) Encoder.cpp

HuffTree.o: TreeNode.o MinHeap.o HuffTree.h HuffTree.cpp
	$(COMP) $(CFLAG) HuffTree.cpp

clean:
	rm huffman *.o
