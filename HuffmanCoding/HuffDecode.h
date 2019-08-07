#pragma once
#ifndef HUFF_D
#define HUFF_D
#include "HuffEncode.h"
#include <vector>
#include <set>
#include <map>

class HuffDecode {

public:
	//std::vector<unsigned char>text;
	std::string dec;
	std::string text;
	std::map<char, std::string> newmap;
	char acc;
	HuffDecode();
	~HuffDecode();
	void decode();
	int readBit(std::ifstream &);
	void readDictFile();
	auto returnMap();
	//std::string findChar(std::string);
	void readEncodedFile();
	char findChar(const std::string&);
	
	

private:
	int index;
	int bitcount;




















};
















#endif