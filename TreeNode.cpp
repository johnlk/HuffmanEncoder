#include "TreeNode.h"

TreeNode::TreeNode(unsigned char value, unsigned int frequency){
	this->value = value;
	this->frequency = frequency;
	this->left = NULL;
	this->right = NULL;
}

bool TreeNode::isLeafNode(){
	return left == NULL || right == NULL;
}

TreeNode* TreeNode::getLeft(){
	return left;
}

TreeNode* TreeNode::getRight(){
	return right;
}

unsigned TreeNode::getValue(){
	return value;
}

unsigned TreeNode::getFrequency(){
	return frequency;
}
