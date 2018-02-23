#include <iostream>
#include "Decoder.h"

Decoder::Decoder(string huff_file_path){
	file_path = huff_file_path;
	total_chars = 0;
	for(int i = 0; i < 256; i++){
		frequency_table[i] = 0;
	}
}

void Decoder::buildFrequencyTableFromFile(){
	FILE *inFile = fopen(file_path.c_str(), "r");
	unsigned int bytes = 0;
	unsigned char charByte = 0;
	fread(&bytes, 2, 1, inFile);
	unique_chars = bytes;
	for(int i = 0; i < unique_chars; i++){
		fread(&charByte, 1, 1, inFile);//read in char
		fread(&bytes, 4, 1, inFile);//read its frequency	
		frequency_table[charByte] = bytes;
		total_chars += bytes;
	}
	fclose(inFile);
}

void Decoder::decode(){
	//build frequency table
	buildFrequencyTableFromFile();
	//min heap
	mh = new MinHeap();
	for(int i = 0; i < 256; i++){
		if(frequency_table[i] > 0){
			TreeNode *node = new TreeNode(i, frequency_table[i]);
			mh->insert(node);
		}
	}
	//construct huff tree
	tree = new HuffTree();	
	tree->buildTree(mh);
}

void Decoder::writeUncompressedFile(string file_path){
	FILE *inFile = fopen(this->file_path.c_str(), "r");
	FILE *outFile = fopen(file_path.c_str(), "w");
	unsigned char byte = 0;
	int byte_count = 0; //for making sure we stop at the last byte buffer bits
	fseek(inFile, 0L, SEEK_END);
	long fileLength = ftell(inFile);
	fseek(inFile, unique_chars*5+2, SEEK_SET);//jumping over the file header
	TreeNode* node = tree->getRoot();
	for(int i = 0; i < fileLength - (unique_chars*5+2); i++){//the -1 is to ignore the final byte
		fread(&byte, 1, 1, inFile);
		for(int i = 0; i < 8; i++){//need to follow a tree path with bits
			if((byte >> 7) == 0){
				node = node->getRight();	
			}else{
				node = node->getLeft();	
			}
			if(node->isLeafNode() && byte_count < total_chars){
				unsigned char character = node->getVal();
				fwrite(&character, 1, 1, outFile);
				node = tree->getRoot();
				byte_count++;
			}else if(byte_count >= total_chars){return;}
			byte <<= 1;
		}
	}
}

Decoder::~Decoder(){
	delete mh;
	delete tree;	
}
