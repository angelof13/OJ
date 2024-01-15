#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "Parameter.h"
#include "IOOperate.h"
#include <algorithm>
using namespace std;

#define M_P_READ vi1    //b,i(int),d(double),c(char),s(string),vi(vector<int>),vvi(vector<vector<int>>),vc(vector<char>),vs(vector<string>),vvs(vector<vector<string>>),vh(vector<head>,list),head,root
#define M_P_WRITE vvi1

class Solution {
public:
	vector<vector<int>> insertSort(vector<int> A) {
		vector<int> temp;
		vector<vector<int>> ret; 
		int n = A.size(),mid=0;
		for (int i = 2; i < n; i++) {
			A[0] = A[i];
			int low = 1, hight = i - 1;
			while (low <= hight) {
				mid = (low + hight) / 2;
				if (A[mid] > A[0]) hight = mid - 1;
				else low = mid + 1;
			}
			temp.push_back(low);
			temp.push_back(hight);
			for (int j = i - 1; j >= hight; j--) {
				A[j + 1] = A[j];
			}
			A[hight + 1] = A[0];
			temp.insert(temp.end(), A.begin()+1, A.end());
			ret.push_back(temp);
			temp.clear();
		}
		temp.insert(temp.end(), A.begin() + 1, A.end());
		ret.push_back(temp);
		return ret;
	}
};
int main(void)
{	
	Solution a;
	IOOperate io;
	Parameter p;
	io.read(p.M_P_READ);
	io.read(p.i1);
	p.M_P_WRITE = a.insertSort(p.M_P_READ);
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