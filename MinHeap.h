#ifndef MINHEAP_H
#define MINHEAP_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class MinHeap{
	private:
		vector<TreeNode*> heap;
		int size;
	public:
		MinHeap();
		TreeNode * removeMin(); //returns root of heap
		void insert(TreeNode * val); //adds element to heap
		int getParent(int);
		int getLeftChild(int);
		int getRightChild(int);
		int getSize(); //returns size of heap
		~MinHeap();
};

#endif
