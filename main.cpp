#include <iostream>
#include <string>
#include "Encoder.h"

using namespace std;

void printHelp(){
	cout << "Type huffman [-e, -d] inputFile outputFile" << endl;
	cout << "-e is for encode -d is for decode" << endl;	
}

int main(int argc, char** argv){
	if(argc < 4){
		printHelp();
		return 1;
	}	
	char mode = argv[1][1];
	char *inFile = argv[2];
	char *outFile = argv[3];

	if(mode == 'e'){
		Encoder *e = new Encoder(inFile);
		e->encode();
		e->writeEncodedFile(outFile);
	}else if(mode == 'd'){
		cout << "decoding: " << inFile << endl;
	}else{
		printHelp();
		return 1;
	}
	return 0;
}
