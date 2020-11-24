#include <iostream>
#include <vector>

#include "Parameter.h"
#include "IOOperate.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int pn = pairs.size();
		sort(pairs);
		for (int i = 0; i < pn; i++) {
			int a = pairs[i][0],b = pairs[i][1];
			if (s[a] > s[b]) {
				swap(s, a, b);
				i = -1;
			}
		}
		return s;
	}
	void swap(string& s, int a, int b) {
		char t = s[a];
		s[a] = s[b];
		s[b] = t;
	}
	void sort(vector<vector<int>>& pairs) {
		int pn = pairs.size();
		vector<int> temp;
		for (int i = 0; i < pn; i++) {
			for (int j = i + 1; j < pn; j++) {
				if (pairs[i][0] > pairs[j][0]) {
					temp = pairs[i];
					pairs[i] = pairs[j];
					pairs[j] = temp;
				}
			}
			
		}
	}
};

enum MyEnum
{
	a,b,c,d,e
};

int main(void)
{	
	Solution a;
	IOOperate io;
	Parameter p;
	string temp = "";
	MyEnum test = b;
	io.read(p.vvi1);
	p.s1 = a.smallestStringWithSwaps(temp,p.vvi1);
	io.write(p.s1);
	return 0;
}

/* 链表
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
			return 1;
		ListNode* spoint = head, * end = spoint, * temp = spoint;
		while (end->next != nullptr)
			end = end->next;
		while (spoint->next != nullptr) {
			if (spoint->val != end->val)
				return 0;
			else {
				while (temp->next != end)
					temp = temp->next;
				if (temp == spoint)
					return 1;
				end = temp;
				spoint = spoint->next;
				temp = spoint;
				if (spoint == end)
					return 1;
			}
		}
		return 1;
	}
};

int main(void)
{
	Solution a;
	IOOperate io;
	Parameter p;
	io.read(p.root);
	p.b = a.isPalindrome(p.head);
	io.write(p.root);
	return 0;
}
*/