#include "IOOperate.h"

IOOperate::IOOperate()
{
	in.open("main_in.txt");
	out.open("main_out.txt");
}
IOOperate::~IOOperate()
{
	in.close();
	out.close();
}

void IOOperate::read(vector<int>& int_o)
{
	int in_temp;
	string stemp;
	stringstream ss;
	getline(in, stemp);
	ss << stemp;
	while (!ss.eof())
	{
		ss >> in_temp;
		int_o.push_back(in_temp);
	}
}
void IOOperate::read(vector<vector<int>>& int_t) 
{
	int in_temp;
	vector<int> in_o;
	string stemp;
	while (getline(in, stemp))
	{
		stringstream ss;
		ss << stemp;
		while (!ss.eof())
		{
			ss >> in_temp;
			in_o.push_back(in_temp);
		}
		int_t.push_back(in_o);
		in_o.clear();
	}
}
void IOOperate::read(vector<vector<char>>& char_t) 
{
	char temp;
	vector<char> char_o;
	string stemp;
	while (getline(in, stemp))
	{
		stringstream ss;
		ss << stemp;
		while (!ss.eof())
		{
			ss >> temp;
			char_o.push_back(temp);
		}
		char_t.push_back(char_o);
		char_o.clear();
	}
}
void IOOperate::read(vector<string>& string_t)
{
	int in_temp;
	string stemp;
	while (getline(in, stemp))
	{
		string_t.push_back(stemp);
	}
}

void IOOperate::read(ListNode* head)
{	
	int i = 0, int_temp = 0;
	string stemp;
	ListNode *node = head;
	while (getline(in, stemp))
	{
		stringstream ss;
		ss << stemp;
		while (!ss.eof())
		{
			ss >> int_temp;
			if (i == 0)
			{
				node->val = int_temp;
				i = 1;
			}
			else
			{
				ListNode* temp = new ListNode;
				temp->val = int_temp;
				node->next = temp;
				node = node->next;
			}
		}
	}
}


void IOOperate::write(vector<int>& int_o) 
{
	for (auto i : int_o)
	{
		out << i << " ";
	}
}
void IOOperate::write(vector<vector<int>>& int_t) 
{
	for (auto i : int_t)
	{
		for (auto j : i)
			out << j << ' ';
		out << endl;
	}
}
void IOOperate::write(vector<vector<char>>& char_t)
{
	for (auto i : char_t)
	{
		for (auto j : i)
			out << j << ' ';
		out << endl;
	}
}
void IOOperate::write(vector<string>& string_t)
{
	for (auto i : string_t)
	{
			out << i << endl;
	}
}

void IOOperate::write(bool& b)
{
	out << b << endl;
}

void IOOperate::write(bool& b, string TRUE, string FALSE)
{
	out << (b ? TRUE : FALSE) << endl;
}

void IOOperate::write(ListNode* head)
{
	ListNode *temp = head;
	while (true)
	{
		out << temp->val << " ";
		if (temp->next == nullptr)
		{
			break;
		}
		temp = temp->next;
	}
	out << endl;
	while (true)
	{
		temp = head;
		if (temp->next == nullptr)
		{
			delete temp;
			break;
		}
		head = head->next;
		delete temp;

	}
}
