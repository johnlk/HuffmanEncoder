#ifndef TREENODE_H
#define TREENODE_H

class TreeNode{
	private:
		TreeNode *left; // pointer to left child
		TreeNode *right; // right child
		unsigned int frequency; // holds the frequency of said character in file
		unsigned char value; // stores char value
	public:
		TreeNode(unsigned char value, unsigned int frequency);
		bool isLeafNode(); // if doesn't have children, would have a char on it
		void join(TreeNode* left, TreeNode* right);
		TreeNode* getLeft();
		TreeNode* getRight();
		unsigned int getFrequency();
		unsigned char getValue();
};

#endif
