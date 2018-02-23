#include "TreeNode.h"

TreeNode::TreeNode(unsigned char val, unsigned int freq){
	this->val = val;
	this->frequency = freq;
	left = NULL;
	right = NULL;
}

bool TreeNode::isLeafNode(){
	return left == NULL || right == NULL;
}

void TreeNode::join(TreeNode *left, TreeNode *right){
	this->left = left;
	this->right = right;
}

TreeNode* TreeNode::getLeft(){
	return left;
}

TreeNode* TreeNode::getRight(){
	return right;
}

unsigned TreeNode::getFrequency(){
	return frequency;
}

unsigned TreeNode::getVal(){
	return val;
}

TreeNode::~TreeNode(){
	left = NULL;
	right = NULL;
}
