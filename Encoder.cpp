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
			//cout << "Char: " << (char)i << " Frequency: " << frequency_table[i] << endl;
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
	//start body
	unsigned int char_byte = 0;
	for(int i = 0; i < inFileSize; i++){
		fread(&char_byte, 1, 1, inFile);
		string byte_str = tree->getCharCode(char_byte);
		//cout << "char: " << (char)char_byte << " code: " << byte_str << endl;
		while(byte_str.size() > 0){ // looping bit by bit left to right in the code
			if(byte_str[0] == '0'){
				byte <<= 1;	
			}else{
				byte <<= 1;
				byte = byte | 1;
			}
			bit_count++;
			if(bit_count % 8 == 0){
				fwrite(&byte, 1, 1, outFile);
				byte = 0;
			}
			byte_str = byte_str.substr(1, byte_str.size() - 1);//remove the first char
		}
	}
	//pad with 0's if we have leftover bits that don't make a full byte
	if(bit_count % 8 != 0){
		do{
			byte <<= 1;
			bit_count++;
		}while(bit_count % 8 != 0);
		fwrite(&byte, 1, 1, outFile);	
	}	
	fclose(inFile);
	fclose(outFile);
}

Encoder::~Encoder(){
	delete mh;
	delete tree;
}
