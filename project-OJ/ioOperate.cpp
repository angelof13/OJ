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
	getline(in, stemp);
	int int_temp = 0, sSize = stemp.size(), weight = 0;
	for (int i = 0; i < sSize; i++) {
		if ('0' <= stemp[i] && '9'>=stemp[i]) {
			int_temp = int_temp * 10 + (stemp[i] - '0');
		}
		else if (stemp[i] == ',' || stemp[i] == ']') {
			weight = 0;
			int_o.push_back(int_temp);
			int_temp = 0;
		}
	}
}
void IOOperate::read(vector<vector<int>>& int_t)
{
	string stemp;
	getline(in, stemp);
	vector<int> in_o;
	int int_temp = 0, firVFlag = 0, sSize = stemp.size(), weight = 0;
	for (int i = 0; i < sSize; i++) {
		if (stemp[i] == '[') {
			firVFlag++;
		}
		else if (stemp[i] == ']') {
			firVFlag--;
			if (firVFlag) {
				weight = 0;
				in_o.push_back(int_temp);
				int_temp = 0;

				int_t.push_back(in_o);
				in_o.clear();
			}
		}
		else if (firVFlag == 2 && '0' <= stemp[i] && '9' >= stemp[i]) {
			int_temp = int_temp * 10 + (stemp[i] - '0');
		}
		else if (firVFlag == 2 && stemp[i] == ',') {
			weight = 0;
			in_o.push_back(int_temp);
			int_temp = 0;
		}
	}
}
void IOOperate::read(vector<char>& char_t)
{
	string stemp;
	getline(in, stemp);
	int sSize = stemp.size(), Flag = 0;
	char ctemp;
	for (int i = 0; i < sSize; i++) {
		if (stemp[i] == '"' && Flag == 0) {
			Flag = 1;
			if (stemp[i + 1] != '"') {
				ctemp = stemp[i++ + 1];
			}
		}
		else if (stemp[i] == '"' && Flag == 1) {
			Flag = 0;
			char_t.push_back(ctemp);
		}
	}
}
void IOOperate::read(string& string_o)
{
	getline(in, string_o);
}
void IOOperate::read(vector<string>& string_t)
{
	string stemp;
	getline(in, stemp);

	int sSize = stemp.size(), Flag = 0, sStart = 0, sLength = 0;
	for (int i = 0; i < sSize; i++) {
		if (stemp[i] == '"' && Flag == 0) {
			Flag = 1;
			sStart = i + 1;
		}
		else if (stemp[i] == '"' && Flag == 1) {
			Flag = 0;
			string_t.push_back(stemp.substr(sStart, sLength));
			sLength = 0;
		}
		else if (Flag == 1) {
			sLength++;
		}
	}
}
void IOOperate::read(vector<vector<string>>& string_t)
{
	string stemp;
	getline(in, stemp);
	vector<string> tempS;
	int sSize = stemp.size(), firVFlag = 0, secVFlag = 0, sStart = 0, sLength = 0;
	for (int i = 0; i < sSize; i++) {
		if (stemp[i] == '[') {
			firVFlag++;
		}
		else if (stemp[i] == ']') {
			firVFlag--;
			if (firVFlag) {
				string_t.push_back(tempS);
				tempS.clear();
			}
		}
		else if (stemp[i] == '"' && secVFlag == 0) {
			secVFlag = 1;
			sStart = i + 1;
		}
		else if (stemp[i] == '"' && secVFlag == 1) {
			secVFlag = 0;
			tempS.push_back(stemp.substr(sStart, sLength));
			sLength = 0;
		}
		else if (secVFlag == 1) {
			sLength++;
		}
	}
}
void IOOperate::read(vector<ListNode*>& vh)
{
	string stemp;
	ListNode* head = new ListNode;
	ListNode* node = head;
	getline(in, stemp);
	int int_temp = 0, sSize = stemp.size(), weight = 0, hdFlag = 0, firFlag = 0;
	for (int i = 0; i < sSize; i++) {
		if (stemp[i] == '[') {
			firFlag++;
		}
		else if (stemp[i] == ']') {
			firFlag--;
			if (firFlag) {
				ListNode* temp = new ListNode(int_temp);
				temp->pre = node;
				node->next = temp;
				hdFlag = 0;
				weight = 0;
				int_temp = 0;
				vh.push_back(head);
				head = new ListNode;
				node = head;

			}
		}
		else if ('0' <= stemp[i] && '9' >= stemp[i]) {
			int_temp = int_temp * 10 + (stemp[i] - '0');
		}
		else if (firFlag==2 && stemp[i] == ',') {
			weight = 0;
			if (hdFlag == 0)
			{
				node->val = int_temp;
				hdFlag = 1;
			}
			else
			{
				ListNode* temp = new ListNode(int_temp);
				temp->pre = node;
				node->next = temp;
				node = node->next;
			}
			int_temp = 0;
		}
	}
}
void IOOperate::read(ListNode*& head)
{
	string stemp;
	head = new ListNode;
	ListNode* node = head;
	getline(in, stemp);
	int int_temp = 0, sSize = stemp.size(), weight = 0, hdFlag = 0;
	for (int i = 0; i < sSize; i++) {
		if ('0' <= stemp[i] && '9'>=stemp[i]) {
			int_temp = int_temp * 10 + (stemp[i] - '0');
		}
		else if (stemp[i] == ',' || stemp[i] == ']') {
			weight = 0;
			if (hdFlag == 0)
			{
				node->val = int_temp;
				hdFlag = 1;
			}
			else
			{
				ListNode* temp = new ListNode(int_temp);
				temp->pre = node;
				node->next = temp;
				node = node->next;
			}
			int_temp = 0;
		}
	}
}
//construct tree abide by root-leftChild-rightChild sequence
void IOOperate::read(TreeNode*& root)
{
	char char_temp;
	string stemp;
	root = new TreeNode(0);
	TreeNode* node = root;
	queue<TreeNode*> list;
	getline(in, stemp);
	int int_temp = 0, sSize = stemp.size(), weight = 0, rtFlag = 0, lrFlag = 1;
	for (int i = 0; i < sSize; i++) {
		if ('0' <= stemp[i] && '9'>=stemp[i]) {
			int_temp = int_temp * 10 + (stemp[i] - '0');
		}
		else if (stemp[i] == 'N' || stemp[i] == 'n') {
			if ((stemp[i + 1] == 'U' || stemp[i + 1] == 'u') && (stemp[i + 2] == 'L' || stemp[i + 2] == 'l') && (stemp[i + 3] == 'L' || stemp[i + 3] == 'l')) {
				if (lrFlag) {
					lrFlag = 0;
				}else{
					if (!list.empty()) {
						node = list.front();
						list.pop();
					}
					lrFlag = 1;
				}
				i = i + 4;
			}
		}
		else if (stemp[i] == ',' || stemp[i] == ']') {
			weight = 0;
			if (rtFlag == 0)
			{
				node->val = int_temp;
				rtFlag = 1;
			}
			else
			{
				TreeNode* temp = new TreeNode(int_temp);
				list.push(temp);
				if (lrFlag) {
					node->left = temp;
					lrFlag = 0;
				}
				else {
					node->right = temp;
					if (!list.empty()) {
						node = list.front();
						list.pop();
					}
					lrFlag = 1;
				}
			}
			int_temp = 0;
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
	out << "["<<endl;
	int size = int_t.size();
	for (int i = 0; i < size; i++)
	{
		int iSize = int_t[i].size();
		out << "[";
		for (int j = 0; j < iSize; j++) {
			out << int_t[i][j] << (j == iSize - 1 ? "" : ",");
		}
		out << (i == size - 1 ? "]" : "],") << endl;
	}
	out << "]" << endl;
}
void IOOperate::write(vector<char>& char_t)
{
	out << "[";
	int size = char_t.size();
	for (int i = 0; i < size; i++)
	{
		out << "\"" << char_t[i] << "\"" << (i == size - 1 ? "]" : ",");
	}
	out << endl;
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
	out << "[";
	while (true)
	{
		out << temp->val << (temp->next == nullptr ? "]" : ",");
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
	int num = 1, allEmpty = 1, rtFlag = 0;
	queue<TreeNode*> list;
	list.push(root);
	out << "[";
	while (!list.empty())
	{
		int n = list.size();
		allEmpty = 1;
		rtFlag = 0;
		out << "[";
		for (int i = 0; i < n; i++)
		{
			TreeNode* t = list.front();
			list.pop();
			if (t != nullptr) {
				if (rtFlag) {
					out << "," << t->val;
				}
				else {
					out << t->val;
					rtFlag = 1;
				}
				if (t->left) {
					list.push(t->left);
					allEmpty = 0;
				}
				else {
					list.push(nullptr);
				}
				if (t->right) {
					list.push(t->right);
					allEmpty = 0;
				}
				else {
					list.push(nullptr);
				}
			}
			else {
				if (rtFlag) {
					out << ",null";
				}
				else {
					out << "null";
					rtFlag = 1;
				}
			}
		}
		out << "]";
		if (allEmpty) {
			break;
		}
		else {
			out << ",";
		}
	}
	out <<"]" << endl;
}
