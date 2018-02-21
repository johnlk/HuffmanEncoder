#include <iostream>
#include "Encoder.h"

Encoder::Encoder(char *filePath){
	unique_chars = 0;
	this->filePath = filePath;
	for(int i = 0; i < 256; i++){ // 255 is max byte value
		frequency_table[i] = 0; // start every byte at 0
	}
}

void Encoder::buildFrequencyTable(){
	FILE *inFile = fopen(this->filePath, "r");
	unsigned int bit = 0;
	//find the number of bytes in the file
	fseek(inFile, 0L, SEEK_END);
	long fileSize = ftell(inFile);
	fseek(inFile, 0L, SEEK_SET);
	//end seeking file size

	//loop through each byte of the file and count occurances
	for(int i = 0; i < fileSize; i++){
		fread(&bit, 1, 1, inFile); //store 1 byte once into bit
		frequency_table[bit]++;
	}	
	fclose(inFile);
}

void Encoder::encode(){
	//build frequency table
	buildFrequencyTable();
	//make min heap
	mh = new MinHeap();
	for(int i = 0; i < frequency_table[i]; i++){
		if(frequency_table[i] > 0){
			TreeNode *newNode = new TreeNode(i, frequency_table[i]);
			mh->insert(newNode);
			unique_chars++;
		}	
	}
	// build huffman tree
	tree = new HuffTree();
	tree->buildTree(mh);
	//generate character codes
	tree->makeCharCodes();
}

void Encoder::writeEncodedFile(char* outFile){

}

Encoder::~Encoder(){
	delete mh;
	delete tree;
}
