#ifndef DECODER_H
#define DECODER_H

#include <string>
#include "MinHeap.h"
#include "HuffTree.h"

class Decoder{
	private:
		unsigned frequency_table[256];
		int unique_chars;
		int total_chars; //keeps track of total bytes
		MinHeap *mh;
		HuffTree *tree;
		string file_path;
	public:
		Decoder(string huff_file_path);
		void buildFrequencyTableFromFile(); //looks at input file's header
		void decode(); //Creates a min-heap and builds the Huffman tree
		void writeUncompressedFile(string file_path); // Writes the uncompressed file and save it as file_path
		~Decoder();
};

#endif
