#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "MinHeap.h"
#include "TreeNode.h"
#include <string>

#define MAXCODELENGTH 256
#define BYTESIZE 8

using namespace std;

class HuffTree{
	private:
		//Add class members and methods	
		TreeNode *root;
		string codes[MAXCODELENGTH];
	public:
		HuffTree();

		//build a hiffman  tree  give a minheap
		void buildTree(MinHeap * mh);

		//generate codes by traversing the huffman tree
		//and store them in an internal data structure (array of strings for example)
		void generateCodes();
	
		void traverseTree(TreeNode *root, string path);

		//returns root of the tree
		TreeNode * getRoot();

		//returns huffman code from  the ascii code
		string getCharCode(int c);
		~HuffTree();
		
};

#endif
