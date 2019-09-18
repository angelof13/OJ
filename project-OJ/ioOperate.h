#ifndef __IOOPERATE
#define __IOOPERATE
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;
class ioOperate {
private:
	ifstream in;
	ofstream out;
public:
	ioOperate();
	~ioOperate();
	void read(vector<int> &int_o);
	void read(vector<vector<int>>& int_t);
	void read(vector<vector<char>>& char_t);
	void read(vector<string>& string_t);

	void write(vector<int>& int_o);
	void write(vector<vector<int>>& int_t);
	void write(vector<vector<char>>& char_t);
	void write(vector<string>& string_t);
	void write(bool& b);
	void write(bool& b,string TRUE,string FALSE);
};
#endif // !__IOOPERATE
#pragma once
