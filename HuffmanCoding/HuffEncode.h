#pragma once
#ifndef HUFF_H
#define HUFF_H
#include <vector>
#include <set>
#include <map>


struct Node {
	//std::string key;
	char key;
	int freq;
	int bitfreq;
	const Node *left, *right,*root;

	Node() {
		left = right = root=nullptr;
		

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
typedef Node* node_ptr;




class HuffEncode {
public:
	std::map<char, std::string> stored_map;
	HuffEncode();
	~HuffEncode();
	void startEncoding(const std::string&);
	void writeToFile(unsigned char&);
	void orderedMap(std::string);
	void writeDict(std::map<char, std::string> &stored_map);

	

private:
	
	int  bitcount;
	unsigned char bit_buffer;
	std::set<Node> nodes_;
	void build_tree(std::set<Node> &s);
	void traverse(const Node *node,std::string str, std::map<char, std::string> &stored_map);
	void writeBit(int bit);
	
};




#endif