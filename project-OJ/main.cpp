#include <iostream>
#include <vector>

#include "Parameter.h"
#include "IOOperate.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int temp = 0,max = nums[0];
		for (auto i : nums)
		{
			temp = temp > 0 ? temp + i : i;
			max = max > temp ? max : temp;
		}
		return max;
	}
};
int main(void)
{	
	Solution a;
	IOOperate io;
	Parameter p;
	io.read(p.vi1);
	p.i1 = a.maxSubArray(p.vi1);
	io.write(p.i1);
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