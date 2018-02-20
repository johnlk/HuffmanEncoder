#ifndef ENCODER_H
#define ENCODER_H

class Encoder{
	private:
		unsigned frequency_table[256]; //how often a byte occures
		int unique_chars; //number of unqiue bytes
		char *filePath;
	public:
		Encoder(char *filePath);
		void buildFrequencyTable();//builds the frequency table from filePath
		void encode();
		void writeEncodedFile(char *outFile);
		~Encoder();
};

#endif
