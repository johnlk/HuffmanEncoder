#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "MinHeap.h"
#include "TreeNode.h"
#include <string>

using namespace std;

class HuffTree{
	private:
		TreeNode *root;
		string codes[256];
	public:
		HuffTree();
		//builds a huffman  tree  give a minheap
		void buildTree(MinHeap * mh);
		//generate codes by traversing the huffman tree
		//and stores them in an array of strings
		void generateCodes();
		void traverseTree(TreeNode *root, string path);
		TreeNode * getRoot(); //returns root of the tree
		string getCharCode(int c);//returns huffman code from char value
		~HuffTree();
};

#endif
