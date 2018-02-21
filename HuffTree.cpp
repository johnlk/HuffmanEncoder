#include "HuffTree.h"

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
		TreeNode *internal = new TreeNode(0, left->getFrequency() + right->getFrequency());
		internal->join(left, right);
		mh->insert(internal);
	}
	if(mh->getSize() == 2){
		left = mh->removeMin();
		right = mh->removeMin();
		root = new TreeNode(0, left->getFrequency() + right->getFrequency());	
		root->join(left, right);
	}
}

//void HuffTree::
