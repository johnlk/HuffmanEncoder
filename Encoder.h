#ifndef ENCODER_H
#define ENCODER_H

#include "MinHeap.h"
#include "HuffTree.h"

class Encoder{
	private:
		unsigned frequency_table[256]; //how often a byte occures
		int unique_chars; //number of unqiue bytes
		char *filePath;
		MinHeap *mh;
		HuffTree *tree;
	public:
		Encoder(char *filePath);
		void buildFrequencyTable();//builds the frequency table from filePath
		void encode();
		void writeEncodedFile(char *outFile);
		~Encoder();
};

#endif
