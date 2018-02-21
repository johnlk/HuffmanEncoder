#ifndef MINHEAP_H
#define MINHEAP_H

#include "TreeNode.h"
#include <vector>

using namespace std;

//this class is for building a min heap of TreeNodes
class MinHeap{
	private:
		vector<TreeNode*> heap;
		int size;		
	public:
		MinHeap();
		TreeNode* removeMin(); // removes the element of least frequency value, later used by Huff Tree
		void insert(TreeNode* node);
		int getParent(int);
		int getLeftChild(int);
		int getRightChild(int);
		int getSize(); //size of the min heap
		~MinHeap();
};

#endif
