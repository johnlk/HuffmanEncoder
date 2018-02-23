#include <iostream>
#include <string>
#include "Encoder.h"
#include "Decoder.h"

using namespace std;

void printHelp(){
	cout << "Invalid arguments." << endl;
	cout << "Type huffman [-e, -d] [input_file] [output_file]" << endl;
	cout << "-e is encode, -d is decode" << endl;
}

int main (int argc, char** argv){
	if(argc < 4){
		printHelp();
		return 1;
	}
	char mode = argv[1][1];
	char *inFile = argv[2];
	char *outFile = argv[3];
	if(mode == 'e'){//encode
		Encoder *e = new Encoder(inFile);
		e->encode();
		e->writeEncodedFile(outFile);
		delete e;
	}else if(mode == 'd'){//decode
		Decoder *d = new Decoder(inFile);
		d->decode();
		d->writeUncompressedFile(outFile);
		delete d;
	}else{
		cout << "Unknow code" << endl;
	}
	return 0;
}
