#include "HuffDecode.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>



HuffDecode::HuffDecode() : bitcount(8){}


void HuffDecode::decode() {
	std::ofstream f;
	std::string str;
	std::string huf;


	
	for (int i = 0; i < text.length(); i++) {

		str.append(sizeof(char),text.at(i));
		char c = findChar(str);

		if (c) {
			huf.append(sizeof(char), c);
			str.clear();
		}
		


	}
	f.open("decoded.txt");
	f << huf;
	f.close();
}



//use stored_map to decode the encoded file 
void HuffDecode:: readEncodedFile() {
	std::ifstream file;
	std::ofstream out_file;

	std::string bitfreq;
	int ch;
	file.open("The Gunslinger.huf", std::ios::in | std::ios::binary); //read from binary file and write again txt file.
	file.read(&acc, sizeof(acc));
	
	while (!file.eof()) {
		int bit = readBit(file);
		char ch = '0' + bit;
		text.append(sizeof(char),ch);
	
		
	}
	file.close();

}

	
auto HuffDecode:: returnMap() {
	return newmap;
}


int HuffDecode::readBit(std::ifstream &fname)
{
	if (bitcount == 0)
	{
		bitcount = 8;
		//acc = readEncodedFile(newmap); //this function must be non-void.
		fname.read(&acc, sizeof(acc));
		
	}
	--bitcount;
	return (acc >> (7 - bitcount)) & 1;
}

void HuffDecode::readDictFile() {
	std::ifstream file;
	//std::string ch;
	char ch;
	std::string bitnum;
	std::string line;
	//std::map<std::string, std::string> newmap;
	file.open("The Gunslinger.dict");
	/*std::stringstream ss(line);*/
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			if (line.empty())
				continue;
			if (line[0] == ' ' && line[1] != ' ') {
				newmap['\n'] = line.substr(1, line.size());
			}
			newmap[line[0]] = line.substr(2, line.size());
		}
		file.close();
	}


	

		
	
	
		

		
	for (auto k: newmap) {
		std::cout << k.first << "===" << k.second << std::endl;
	}

	
}
char HuffDecode::findChar(const std::string &str)
{
	std::string ch;
	for (auto k : newmap) {
		if (str == k.second) {
			ch = k.first;
			
		}
	}
	if (*ch.c_str()) {
		char a = *ch.c_str();
		return a;
	}
	else
		return NULL;
	
	
}
