#include "HuffTree.h"
#include <iostream>

HuffTree::HuffTree(){
	root = NULL;
}

void HuffTree::buildTree(MinHeap* mh){
	TreeNode *left;
	TreeNode *right;
	//go through min heap and keep removing min elements, to construct huff tree
	while(mh->getSize() > 2){
		left = mh->removeMin();
		right = mh->removeMin();
		cout << "Left: " << (char)left->getValue() << " Right: " << (char)right->getValue() << endl;
		TreeNode *internal = new TreeNode(0, left->getFrequency() + right->getFrequency());
		cout << "Total Frequency: " << internal->getFrequency() << endl;
		internal->join(left, right);
		mh->insert(internal);
	}
	if(mh->getSize() == 2){//this little section ensure the root is got the right pointers
		left = mh->removeMin();
		right = mh->removeMin();
		root = new TreeNode(0, left->getFrequency() + right->getFrequency());	
		root->join(left, right);
	}
}

void HuffTree::traverseTree(TreeNode* root, string path){
	if(root == NULL){return;}
	if(root->isLeafNode()){
		char_codes[root->getValue()] = path;
	}
	traverseTree(root->getLeft(), path + "1");
	traverseTree(root->getRight(), path + "0");
}

void HuffTree::makeCharCodes(){
	traverseTree(this->root, "");
}

TreeNode* HuffTree::getRoot(){
	return root;
}

string HuffTree::getCharCode(int i){
	return char_codes[i];
}

HuffTree::~HuffTree(){
	delete root;
}
