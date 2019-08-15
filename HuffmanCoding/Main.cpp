#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <set>
#include <vector>
#include <map>
#include "HuffEncode.h"
#include "HuffDecode.h"


int main(int argc, char *argv[])
{
	//std::cout << "Enter a valid character to read the given file." << std::endl;
	//char fname;
	//std::cin >> fname;

	/////////////decode ve encode etmek i�in ayr� ayr� komut al (kullan�c�dan)
	////dosyaya surekli eklenmesini engelle

	std::string fname;
	std::cout << "Enter a file." << std::endl;
	getline(std::cin, fname);


	HuffEncode h;
	h.startEncoding(fname);  //// sadece bu fonksiyon public olsun.
	h.orderedMap(fname);   /////bu dosyay� mainde �a��rma.
	HuffDecode d;
	d.readDictFile();
	d.readEncodedFile();
	d.decode();
	system("pause");
}

