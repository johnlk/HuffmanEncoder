#include "MinHeap.h"

// going to use the array implementation of a min heap
MinHeap::MinHeap(){
	size = 0;
}

int MinHeap::getParent(int i){
	return (i-1)/2;
}

int MinHeap::getLeftChild(int i){
	return 2*i+1;
}

int MinHeap::getRightChild(int i){
	return 2*i+2;
}

void MinHeap::insert(TreeNode* node){
	heap.push_back(node);
	size++;
	//if the inserted node has a frequency smaller than parent node, then upheap
	int i = size - 1;
	TreeNode *holder;
	while(i > 0 && heap[i]->getFrequency() < heap[getParent(i)]->getFrequency()){
		int parent = getParent(i);
		holder = heap[i];
		heap[i] = heap[parent];
		heap[parent] = holder;
		i = parent;
	}
}

TreeNode* MinHeap::removeMin(){
	if(size < 1){return 1;}
	size--;
	//swap top and last value
	TreeNode *holder = heap[0];
	heap[0] = heap[size];
	heap[size] = holder;
	//last value has our removed node
	//now downheap the swapped value
	int i = 0;
	int leftChild = getLeftChild(i);
	int rightChild = getRightChild(i);	
	//checking if child nodes are greater than downheaping node
	while( (leftChild < size && heap[i]->getFrequency() > heap[leftChild]->getFrequency()) ||
				(rightChild < size && heap[i]->getFrequency() > heap[rightChidl]->getFrequency() ){
		if(rightChild >= size || heap[leftChild]->getFrequency() <= heap[rightChild]->getFrequency()){
			holder = heap[leftChild];
			heap[leftChild] = heap[i];
			heap[i] = holder;
		}else{
			holder = heap[rightChild];
			heap[rightChild] = heap[i];
			heap[i] = holder;
		}
		leftChild = getLeftChild(i);
		rightChild = getRightChild(i);	
	}
}

int MinHeap::getSize(){
	return size;
}

MinHeap::~MinHeap(){

}
