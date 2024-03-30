#ifndef __IOOPERATE
#define __IOOPERATE
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>

#include "Parameter.h"
using namespace std;

class IOOperate {
private:
	ifstream in;
	ofstream out;

	void read(int& i);
	void read(vector<int>& int_o);
	void read(vector<vector<int>>& int_t);
	void read(vector<char>& char_t);
	void read(string& string_o);
	void read(vector<string>& string_t);
	void read(vector<vector<string>>& string_t);
	void read(vector<ListNode*>& vh);
	void read(ListNode*& head);
	void read(TreeNode*& root);

	template<typename T>
	void write(T o) {
		out << "[" << o << "]" << endl;
	};

	void write(string& s);
	void write(vector<int>& int_o);
	void write(vector<vector<int>>& int_t);

	template<typename T>
	void write(vector<T>& o) {
		out << "[";
		for (auto i = o.cbegin(); i < o.cend(); i++)
		{
			out << "\"" << *i << "\"" << (i == o.cend() - 1 ? "]" : ",");
		}
		out << endl;
	};

	void write(vector<vector<string>>& string_t);
	void write(bool& b);
	void write(bool& b, string TRUE, string FALSE);
	void write(ListNode* head);
	void write(TreeNode* root);

public:
	IOOperate();
	~IOOperate();

	template<typename T>
	void IORead(T& end) {
		this->read(end);
	};

	template<typename T, typename IREAD>
	void IORead(T& first, IREAD& iRead...) {
		this->read(first);
		IORead(iRead);
	};

	template<typename IWRITE>
	void IOWrite(IWRITE first) {
		this->write(first);
	};

};
#endif // !__IOOPERATE
#pragma once


