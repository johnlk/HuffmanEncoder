#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode(char value, unsigned int frequency){
	this->value = value;
	this->frequency = frequency;
	this->left = NULL;
	this->right = NULL;
}

bool TreeNode::isLeafNode(){
	return left == NULL || right == NULL;
}

void TreeNode::join(TreeNode* left, TreeNode* right){
	this->left = left;
	this->right = right;
}

TreeNode* TreeNode::getLeft(){
	return left;
}

TreeNode* TreeNode::getRight(){
	return right;
}

char TreeNode::getValue(){
	return value;
}

unsigned int TreeNode::getFrequency(){
	return frequency;
}
