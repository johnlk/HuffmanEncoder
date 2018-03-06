#include "HuffTree.h"

using namespace std;

HuffTree::HuffTree(){
	root = NULL;
}

void HuffTree::buildTree(MinHeap *mh){
	TreeNode *left;
	TreeNode *right;
	//repeatedly pull off the min values and keep re-adding to heap
	while(mh->getSize() > 2){
		left = mh->removeMin();
		right = mh->removeMin();
		TreeNode *internal = new TreeNode(0, left->getFrequency() + right->getFrequency());//internal node
		internal->join(left, right);
		mh->insert(internal);
	}
	//makes sure root holds the correct value
	if(mh->getSize() == 2){
		left = mh->removeMin();
		right = mh->removeMin();
		root = new TreeNode(0, left->getFrequency() + right->getFrequency());
		root->join(left, right);
	}
}

void HuffTree::traverseTree(TreeNode *root, string path){
	if(root == NULL){return;}
	if(root->isLeafNode()){
		codes[root->getVal()] = path;
	}
	traverseTree(root->getLeft(), path + "1");
	traverseTree(root->getRight(), path + "0");
}

void HuffTree::generateCodes(){
	//recursively traverse tree, add to codes array
	traverseTree(root, "");
}

TreeNode* HuffTree::getRoot(){
	return root;
}

string HuffTree::getCharCode(int c){
	return codes[c];
}

void deleteTree(TreeNode *root){
	if(root == NULL){return;}
	deleteTree(root->getLeft());
	deleteTree(root->getRight());
	delete root;
}

HuffTree::~HuffTree(){
	//recursively destroy the tree
	deleteTree(this->root);
	root = NULL;
}
