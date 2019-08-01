#ifndef HUFF_D
#define HUFF_D
#include "HuffEncode.h"
#include <vector>
#include <set>
#include <map>

class HuffDecode {

public:
	HuffDecode();
	void decode();
	int readBit();
	void readDictFile();



private:
	int index;
	unsigned char acc;
	int bitcount;




















};
















#endif