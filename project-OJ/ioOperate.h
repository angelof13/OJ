#ifndef __IOOPERATE
#define __IOOPERATE
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

#include "Parameter.h"
using namespace std;

class IOOperate {
private:
	ifstream in;
	ofstream out;
public:
	IOOperate();
	~IOOperate();
	void read(int& i);
	void read(vector<int> &int_o);
	void read(vector<vector<int>>& int_t);
	void read(vector<char>& char_t);
	void read(string& string_o);
	void read(vector<string>& string_t);
	void read(vector<vector<string>>& string_t);
	void read(vector<ListNode*>& vh);
	void read(ListNode*& head);
	void read(TreeNode*& root);

	void write(int int_o);
	void write(double double_o);
	void write(string s);
	void write(vector<int>& int_o);
	void write(vector<vector<int>>& int_t);
	void write(vector<char>& char_t);
	void write(vector<string>& string_t);
	void write(vector<vector<string>>& string_t);
	void write(bool& b);
	void write(bool& b,string TRUE,string FALSE);
	void write(ListNode* head);
	void write(TreeNode* root);
};
#endif // !__IOOPERATE
#pragma once
