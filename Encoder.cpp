#include "Encoder.h"

Encoder::Encoder(char *filePath){
	unique_chars = 0;
	this->filePath = filePath;
	for(int i = 0; i < 256; i++){ // 255 is max byte value
		frequency_table[i] = 0; // start every byte at 0
	}
}
