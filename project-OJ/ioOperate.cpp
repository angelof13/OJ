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

void IOOperate::read(int& i)
{
	in >> i;
}
void IOOperate::read(vector<int>& int_o)
{
	string stemp;
	while (getline(in, stemp))
	{
		int in_temp = 0, sSize = stemp.size(), weight = 0;
		for (int i = 0; i < sSize; i++) {
			if (stemp[i] != ',' && stemp[i] != '[' && stemp[i] != ']') {
				in_temp = in_temp * 10 + (stemp[i] - '0');
			}
			else if (stemp[i] == ',' || stemp[i] == ']') {
				weight = 0;
				int_o.push_back(in_temp);
				in_temp = 0;
			}
		}
	}
}
void IOOperate::read(vector<vector<int>>& int_t) 
{
	string stemp;
	while (getline(in, stemp))
	{
		vector<int> in_o;
		int in_temp = 0, firVflag = 0, sSize = stemp.size(), weight = 0;
		for (int i = 0; i < sSize; i++) {
			if (stemp[i] == '[') {
				firVflag++;
			}
			else if (stemp[i] == ']') {
				firVflag--;
				if (firVflag) {
					weight = 0;
					in_o.push_back(in_temp);
					in_temp = 0;

					int_t.push_back(in_o);
					in_o.clear();
				}
			}
			else if (firVflag==2 && stemp[i] != ',') {
				in_temp = in_temp * 10 + (stemp[i] - '0');
			}
			else if (firVflag == 2 && stemp[i] == ',') {
				weight = 0;
				in_o.push_back(in_temp);
				in_temp = 0;
			}
		}
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
		while (ss.peek() != EOF)
		{
			ss >> temp;
			char_o.push_back(temp);
		}
		char_t.push_back(char_o);
		char_o.clear();
	}
}void IOOperate::read(string& string_o)
{
	getline(in, string_o);
}
void IOOperate::read(vector<string>& string_t)
{
	string stemp;
	while (getline(in, stemp))
	{
		int sSize = stemp.size(), flag = 0, sStart = 0, sLength = 0;
		for (int i = 0; i < sSize; i++) {
			if (stemp[i] == '"' && flag == 0) {
				flag = 1;
				sStart = i + 1;
			}
			else if (stemp[i] == '"' && flag == 1) {
				flag = 0;
				string_t.push_back(stemp.substr(sStart, sLength));
				sLength = 0;
			}
			else if (flag == 1) {
				sLength++;
			}
		}
	}
}
void IOOperate::read(vector<vector<string>>& string_t)
{
	string stemp;
	while (getline(in, stemp))
	{
		vector<string> tempS;
		int sSize = stemp.size(), firVflag = 0, secVflag = 0, sStart = 0, sLength = 0;
		for (int i = 0; i < sSize; i++) {
			if (stemp[i] == '[') {
				firVflag++;
			}
			else if (stemp[i] == ']') {
				firVflag--;
				if (firVflag) {
					string_t.push_back(tempS);
					tempS.clear();
				}
			}
			else if (stemp[i] == '"' && secVflag == 0) {
				secVflag = 1;
				sStart = i + 1;
			}
			else if (stemp[i] == '"' && secVflag == 1) {
				secVflag = 0;
				tempS.push_back(stemp.substr(sStart, sLength));
				sLength = 0;
			}
			else if (secVflag == 1) {
				sLength++;
			}
		}
	}
}
void IOOperate::read(vector<ListNode*>& vh)
{
	int int_temp = 0;
	string stemp;
	while (getline(in, stemp))
	{
		int i = 0;
		ListNode* head = new ListNode;
		ListNode* node = head;
		stringstream ss;
		ss << stemp;
		while (ss.peek() != EOF)
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
		vh.push_back(head);
	}
}
void IOOperate::read(ListNode*& head)
{	
	int i = 0, int_temp = 0;
	string stemp;
	head = new ListNode;
	ListNode *node = head;
	getline(in, stemp);
	stringstream ss;
	ss << stemp;
	while (ss.peek() != EOF)
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

void IOOperate::read(TreeNode*& root)
{
	int flag = -1,int_temp;
	char char_temp;
	string stemp;
	root = new TreeNode(0);
	TreeNode* node = root;
	queue<TreeNode*> list;
	while (getline(in, stemp))
	{
		stringstream ss;
		ss << stemp;
		while (ss.peek() != EOF)
		{
			ss >> char_temp;
			int_temp = char_temp - '0';
			if (flag == -1)
			{
				node->val = int_temp;
				list.push(node);
				flag = 0;
			}
			else
			{
				TreeNode* temp = new TreeNode(int_temp);
				if (flag) {
					if (char_temp != '$') {
						node->right = temp;
						list.push(temp);
					}
					list.pop();
				}
				else {
					node = list.front();
					if (char_temp != '$'){
						node->left = temp;
						list.push(temp);
					}
				}
				flag = !flag;
			}
		}
	}
}

void IOOperate::write(int int_o)
{
	out << "[" << int_o << "]";
}

void IOOperate::write(double double_o)
{
	out << "[" << double_o << "]";
}

void IOOperate::write(string s)
{
	out << "[\"" << s << "\"]";
}

void IOOperate::write(vector<int>& int_o)
{
	out << "[";
	int size = int_o.size();
	for (int i = 0; i < size; i++)
	{
		out << int_o[i] << (i == size - 1 ? "" : ",");
	}
	out << "]" << endl;
}
void IOOperate::write(vector<vector<int>>& int_t) 
{
	out << "[";
	int size = int_t.size();
	for (int i = 0; i < size; i++)
	{
		int iSize = int_t[i].size();
		out << "[";
		for (int j = 0; j < iSize; j++) {
			out << int_t[i][j] << (j == iSize - 1 ? "" : ",");
		}
		out << (i == size - 1 ? "]" : "],");
	}
	out << "]" << endl;
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
	out << "[";
	int size = string_t.size();
	for (int i = 0; i < size; i++)
	{
		out << "\"" << string_t[i] << "\"" << (i == size - 1 ? "]" : ",");
	}
	out << endl;
}
void IOOperate::write(vector<vector<string>>& string_t)
{
	out << "[";
	int size = string_t.size();
	for (int i = 0; i < size; i++)
	{
		int iSize = string_t[i].size();
		out << "[";
		for (int j = 0; j < iSize; j++)
		{
			out << "\"" << string_t[i][j] << "\"" << (j == iSize - 1 ? "" : ",");
		}
		out << (i == size - 1 ? "]" : "],");
	}
	out << "]" << endl;
}

void IOOperate::write(bool& b)
{
	out << (b ? "TRUE" : "FALSE") << endl;
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

void IOOperate::write(TreeNode* root)
{
	int num = 1,eflag = 0;
	queue<TreeNode*> list;
	list.push(root);
	while (list.size()) {
		for (int i = 0; i < num; i++) {
			if (list.front() != nullptr) {
				out << list.front()->val << ' ';
				if (list.front()->left != nullptr) {
					list.push(list.front()->left);
				}
				else {
					list.push(nullptr);
					eflag++;
				}
				if (list.front()->right != nullptr) {
					list.push(list.front()->right);
				}
				else {
					list.push(nullptr);
					eflag++;
				}
			}
			else {
				out << '$'<< ' ';
				list.push(nullptr);
				list.push(nullptr);
				eflag++;
			}
			list.pop();
		}
		num = list.size();
		if (eflag == num) {
			break;
		}
		out << endl;
	}
}
