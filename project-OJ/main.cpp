#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <functional>

#include "Parameter.h"
#include "IOOperate.h"

using namespace std;

class Solution {
public:
	int func(int target) {
		return 0;
	}
};

template<typename IWRITE, typename... IREAD >
void process(IWRITE& iWrite, IREAD&... iReads) {
	IOOperate io;
	Solution a;
	io.IORead(iReads...);
	iWrite = a.func(iReads...);
	io.IOWrite(iWrite);
};
int main(void)
{
	Parameter p;
	process(p.i2, p.i1);
	return 0;
};