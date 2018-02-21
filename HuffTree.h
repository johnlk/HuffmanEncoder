#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "MinHeap.h"
#include "TreeNode.h"

using namespace std;

class HuffTree{
	private:
		TreeNode *root;
		char* char_codes[256];
	public:
		HuffTree();
		void buildTree(MinHeap* mh); // build tree from min heap
		void makeCharCode(); // stores the code for a character of the tree in char_codes
		TreeNode* getRoot();
		char* getCharNode(int);
		~HuffTree();		
};


#endif
