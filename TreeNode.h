#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

class TreeNode{
	private:
		TreeNode *left; // pointer to left child
		TreeNode *right; // right child
		unsigned int frequency; // holds the frequency of said character in file
		unsigned char value; // stores char value
	public:
		TreeNode(unsigned char value, unsigned int frequency);
		bool isLeafNode(); // if doesn't have children, would have a char on it
		TreeNode* getLeft();
		TreeNode* getRight();
		unsigned getFrequency();
		unsigned char getValue();
};

#endif
