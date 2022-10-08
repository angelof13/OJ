#include <iostream>
#include <vector>

#include "Parameter.h"
#include "IOOperate.h"
#include <algorithm>
using namespace std;

#define M_P_READ i1
#define M_P_WRITE c1

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

	}
};
int main(void)
{	
	Solution a;
	IOOperate io;
	Parameter p;
	io.read(p.M_P_READ);
	//p.M_P_WRITE = a.groupAnagrams(p.vs1);
	io.write(p.M_P_WRITE);
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