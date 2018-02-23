#include "Encoder.h"

Encoder::Encoder(string file_path){
	unique_chars = 0;
	this->file_path = file_path;
	for(int i = 0; i < 256; i++){
		frequency_table[i] = 0;
	}
}

void Encoder::buildFrequencyTable(){
	FILE *inFile = fopen(file_path.c_str(), "r");
	unsigned int byte = 0;
	fseek(inFile, 0L, SEEK_END);
	long fileLength = ftell(inFile);
	fseek(inFile, 0L, SEEK_SET);
	for(int i = 0; i < fileLength; i++){
		fread(&byte, 1, 1, inFile);
		frequency_table[byte]++;
	}
	fclose(inFile);
}

void Encoder::encode(){
	//frequency table
	buildFrequencyTable();	
	//minheap
	mh = new MinHeap();
	for(int i = 0; i < 256; i++){
		if(frequency_table[i] > 0){
			unique_chars++;
			TreeNode *node = new TreeNode(i, frequency_table[i]);
			mh->insert(node);
		}
	}
	//huffman
	tree = new HuffTree();
	tree->buildTree(mh);
	//code for each char
	tree->generateCodes();
}

void Encoder::writeEncodedFile(string output_file_path){
	FILE *inFile = fopen(file_path.c_str(), "r");
	FILE *outFile = fopen(output_file_path.c_str(), "w");
	//get size of file
	fseek(inFile, 0L, SEEK_END);
	long fileLength = ftell(inFile);
	fseek(inFile, 0L, SEEK_SET);
	//reset position
	char c;
	int bitCount = 0;
	unsigned int byte; //multiple bytes actually
	byte = unique_chars;
	//start header
	fwrite(&byte, 2, 1, outFile);	
	for(int i = 0; i < 256; i++){
		if(frequency_table[i] > 0){
			//char byte
			byte = i;
			fwrite(&byte, 1, 1, outFile);	
			//frequency bytes
			byte = frequency_table[i];
			fwrite(&byte, 4, 1, outFile);	
		}
	}
	//end header
	//begin file
	unsigned int charByte = 0;
	for(int i = 0; i < fileLength; i++){
		fread(&charByte, 1, 1, inFile);
		string bit_str = tree->getCharCode(charByte);
		while(bit_str.size() > 0){
			if(bit_str[0] == '0'){
				byte <<= 1;
			}else{
				byte <<= 1;
				byte = byte | 1;	
			}
			bitCount++;
			if(bitCount % 8 == 0){//now we can write one byte
				fwrite(&byte, 1, 1, outFile);	
				byte = 0;
			}
			bit_str = bit_str.substr(1, bit_str.size()-1);
		}
	}
	//padding with 0's
	if(bitCount % 8 != 0){
		while(bitCount % 8 != 0){
			byte <<= 1;
			bitCount++;
		}
		fwrite(&byte, 1, 1, outFile);	
	}
	fclose(inFile);
	fclose(outFile);
}

Encoder::~Encoder(){
	delete tree;
	delete mh;
}
