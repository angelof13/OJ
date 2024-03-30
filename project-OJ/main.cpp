#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <functional>

#include "Parameter.h"
#include "IOOperate.h"

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {

	}
};

template<typename IWRITE, typename... IREAD >
void process(IWRITE& iWrite, IREAD&... iReads) {
	IOOperate io;
	Solution a;
	io.IORead(iReads...);
	iWrite = a.findSubstring(iReads...);
	io.IOWrite(iWrite);
};
int main(void)
{
	Parameter p;
	process(p.vi2, p.s1,p.vi1);
	return 0;
};