#include "HuffDecode.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>


HuffDecode::HuffDecode() {
	
	
}


void HuffDecode::decode() {

}

//use stored_map to decode the encoded file 




int HuffDecode::readBit()
{
	if (bitcount == 0)
	{
		bitcount = 8;
		///acc = readbyte();            
	}
	--bitcount;
	return (acc >> (7 - bitcount)) & 1;
}

void HuffDecode::readDictFile() {
	std::ifstream file;

	file.open("The Gunslinger.dict");
	

}