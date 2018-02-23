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
	unsigned int byte = 0;
	//find the number of bytes in the file
	fseek(inFile, 0L, SEEK_END);
	long fileSize = ftell(inFile);
	fseek(inFile, 0L, SEEK_SET);
	//end seeking file size

	//loop through each byte of the file and count occurances
	for(int i = 0; i < fileSize; i++){
		fread(&byte, 1, 1, inFile); //store 1 byte once into bit
		frequency_table[byte]++;
	}	
	fclose(inFile);
}

void Encoder::encode(){
	//build frequency table
	buildFrequencyTable();
	//make min heap
	mh = new MinHeap();
	for(int i = 0; i < 256; i++){
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

void Encoder::writeEncodedFile(char* filePath){
	FILE *inFile = fopen(this->filePath, "r");
	FILE *outFile = fopen(filePath, "w");
	//get size of inFile
	fseek(inFile, 0L, SEEK_END);
	long inFileSize = ftell(inFile);
	fseek(inFile, 0L, SEEK_SET);
	
	char c;
	int bit_count = 0;
	unsigned int byte = unique_chars;	//byte can be multiple bytes, up to 4 according to int
	//writting the header
	cout << "Unique chars: " << byte << endl;
	fwrite(&byte, 2, 1, outFile);
	for(int i = 0; i < 256; i++){
		if(frequency_table[i] > 0){
			//character byte
			byte = i;
			fwrite(&byte, 1, 1, outFile);
			//frequency byte	
			byte = frequency_table[i];
			fwrite(&byte, 4, 1, outFile);
		}	
	}
	//end header
}

Encoder::~Encoder(){
	delete mh;
	delete tree;
}
