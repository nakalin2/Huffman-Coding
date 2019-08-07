#include "HuffEncode.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>



HuffEncode::HuffEncode() : bitcount(0) {
	//bitcount = 0;
	
	
}
HuffEncode::~HuffEncode(){}

void HuffEncode::startEncoding(const std::string &fname) {  //read the txt file and find the frequencies
	char letter;

	std::ifstream file;
	std::map<char, int> m;
	std::set<Node> initial_nodes;

	file.open(fname.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			file >> std::noskipws >> letter;
			m[letter]++;
		}
		file.close();
	}

	for (auto num : m)
	{
		std::cout << num.first << " " << num.second << std::endl;
	}
	for (auto n : m) {
		Node temp;
		temp.key = n.first;
		temp.freq = n.second;
		initial_nodes.insert(temp);
	}
	build_tree(initial_nodes);

}

void HuffEncode::build_tree(std::set<Node> &s) {
	while (s.size() > 1) { 

		Node left = *s.begin();
		s.erase(s.begin());

		Node right = *s.begin();
		s.erase(s.begin());

		Node root;
		root.freq = left.freq + right.freq;
		root.key = left.key + right.key;
		s.insert(root);

		nodes_.insert(left);
		nodes_.insert(right);
		root.left = &(*nodes_.find(left));
		root.right = &(*nodes_.find(right));

		nodes_.insert(root);
	}
	
	for (auto& n : nodes_)
	{
		std::cout << n.key << " " << n.freq << "\n";
	}

	
	
	Node current = *nodes_.rbegin();
	traverse(&current,"",stored_map);
	
}


void HuffEncode::traverse(const Node *node, std::string str, std::map<char, std::string> &stored_map) {

	if (node == nullptr)
		return;

	if (!node->left && !node->right) {
		if (node->key == '\n') {
			stored_map['\n'] = str;

		}
		if (node->key ==' ') {
			stored_map[' '] = str;
		}
		if(node->key !=' ' && node->key !='\n') {
			stored_map[node->key] = str;
		}
	}


	traverse(node->left, str + "0", stored_map);
	traverse(node->right, str + "1", stored_map);
	
	
}


void HuffEncode::writeBit(int bit) {
	
	bit_buffer |= (bit << bitcount);

	if (++bitcount == 8)
	{
		//std::cout << bit_buffer << " BUFFER" << std::endl;
		writeToFile(bit_buffer);
		bit_buffer = 0;
		bitcount = 0;
	}
}



void HuffEncode::writeToFile(unsigned char &bit_buffer) {
	std::ofstream file;

	file.open("The Gunslinger.huf",std::ios::binary | std::ios::app);     
	file.write((char*)&bit_buffer, sizeof(bit_buffer));
	

	file.close();

	

}




void HuffEncode::orderedMap(std::string fname) {
	
	std::ifstream file;
	char letter;
	int bit;
	char ch;
	std::string bitfreq;
	file.open(fname.c_str());
	if (file.is_open()) {
		while (!file.eof()) {

			file >> std::noskipws >> letter;

			bitfreq = stored_map[letter];

			for (int i = 0; i < bitfreq.size(); i++) {
				ch = bitfreq[i];
				bit = ch - '0';
				writeBit(bit);
			}
		}
		file.close();

	}
	////////////////////////////////////////////////////////
	/*for (auto b : stored_map) {
				if (std::string{ letter } == b.first) {
					bitfreq = b.second;

					for (int i = 0; i < b.second.size(); i++) {
						ch = bitfreq[i];
						bit = ch - '0';

						writeBit(bit);
					}

				}
	}*/
	//////////////////////////////////////////////////////////

	for (auto num : stored_map)
	{
		std::cout << num.first << " " << num.second << std::endl;
	}
	
	writeDict(stored_map);
	
}

void HuffEncode::writeDict(std::map<char, std::string> &stored_map) {
	std::ofstream file;

	file.open("The Gunslinger.dict");    
	
	for (const auto& kv : stored_map) {
		file << kv.first << " " << kv.second << std::endl;
		
	}
	file.close();

	

}
