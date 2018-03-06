#include "MinHeap.h"

//array based min heap
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

void MinHeap::insert(TreeNode * val){
	heap.push_back(val);
	size++;
	int i = size - 1;
	TreeNode *holder;
	while(i > 0 && heap[i]->getFrequency() < heap[getParent(i)]->getFrequency()){ //if added node is less than parent, upheap
		int parent = getParent(i);
		holder = heap[i];
		heap[i] = heap[parent];
		heap[parent] = holder;
		i = parent;
	}
}

int MinHeap::getSize(){
	return size;
}

TreeNode * MinHeap::removeMin(){
	if(size < 1){
		return NULL;
	}
	size--;
	//swap the head and the bottom
	TreeNode* holder = heap[0];
	heap[0] = heap[size];
	heap[size] = holder;
	//now down heap
	int i = 0;
	int leftChild = getLeftChild(i);
	int rightChild = getRightChild(i);
	while((leftChild < size && heap[i]->getFrequency() > heap[leftChild]->getFrequency()) ||
			  (rightChild < size && heap[i]->getFrequency() > heap[rightChild]->getFrequency())){//down heaping and maintaing the min heap
		if(rightChild >= size || heap[leftChild]->getFrequency() <= heap[rightChild]->getFrequency()){
			holder = heap[leftChild];
			heap[leftChild] = heap[i];
			heap[i] = holder;
			i = leftChild;
		}else{
			holder = heap[rightChild];
			heap[rightChild] = heap[i];
			heap[i] = holder;
			i = rightChild;	
		}
		leftChild = getLeftChild(i);
		rightChild = getRightChild(i);
	}
	holder = heap[size];
	heap.erase(heap.begin() + size);
	return holder;
}

MinHeap::~MinHeap(){
	
}
