#ifndef ENCODER_H
#define ENCODER_H

#include <string>
#include "TreeNode.h"
#include "MinHeap.h"
#include "HuffTree.h"

using namespace std;

class Encoder{
	private:
		unsigned frequency_table[256];
		int unique_chars;
		MinHeap *mh;
		HuffTree *tree;
		string file_path;
	public:
		Encoder(string file_path); 
		void buildFrequencyTable(); //fills array at char value with their frequency
		void encode();//build min heap, huff tree
		void writeEncodedFile(string output_file_path);
		~Encoder();
};

#endif
