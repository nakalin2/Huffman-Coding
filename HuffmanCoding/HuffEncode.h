#ifndef HUFF_H
#define HUFF_H
#include "HuffDecode.h"
#include <vector>
#include <set>
#include <map>


struct Node {
	std::string key;
	int freq;
	int bitfreq;
	const Node *left, *right;

	Node() {
		left = right = nullptr;
		

	}
	

	bool operator<(const Node& rhs) const {
		if (freq != rhs.freq)
		{
			return freq < rhs.freq;
		}		
		else
		{
			return key < rhs.key;
		}
		
	}
};




class HuffEncode {
public:

	HuffEncode();
	void startEncoding(std::string);
	void writeBit(int bit);
	void writeToFile(unsigned char&);
	std::map<std::string, std::string> stored_map;
	void orderedMap(std::string);
	void writeDict(std::map<std::string, std::string> &stored_map);
	
	
	

private:
	
	int  bitcount;
	unsigned char bit_buffer;
	void build_tree(std::set<Node> &s);
	void traverse(const Node *node,std::string str, std::map<std::string, std::string> &stored_map);
	std::set<Node> nodes_;
	
};




#endif