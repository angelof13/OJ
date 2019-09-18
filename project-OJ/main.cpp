#include <iostream>
#include "ioOperate.h"
#include <vector>
using namespace std;

class Solution {
public:
	void function(void*) {
		
	}
};



int main(void)
{	
	Solution a;
	ioOperate io;
	vector<int> in1,out1;
	vector<vector<int>>in2, out2;
	vector<string> ins,outs;
	ListNode* head = new ListNode();
	io.read(in1);
	a.function(&in1);
	io.write(in1);
	return 0;
}
