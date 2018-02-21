#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "MinHeap.h"
#include "TreeNode.h"
#include <string>

using namespace std;

class HuffTree{
	private:
		TreeNode *root;
		string char_codes[256];
	public:
		HuffTree();
		void buildTree(MinHeap* mh); // build tree from min heap
		void traverseTree(TreeNode* root, string path);//recursive call that helps make char_codes
		void makeCharCodes(); // stores the code for a character of the tree in char_codes
		TreeNode* getRoot();
		string getCharCode(int);
		~HuffTree();		
};


#endif
