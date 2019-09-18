#include <iostream>
#include <vector>

#include "Parameter.h"
#include "IOOperate.h"
using namespace std;

class Solution {
public:
	void function(void*) {
		
	}
};

int main(void)
{	
	Solution a;
	IOOperate io;
	Parameter p;
	io.read(p.head);
	a.function(&p.head);
	io.write(p.head);
	return 0;
}
