#include <iostream>
#include "ioOperate.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> value;
		int flag3 = 2, flag5 = 4;
		for (int i = 1; i <= n; i++) {
			if (flag3 == 0 && flag5 == 0) {
				value.push_back("FizzBuzz");
				flag3 = 3, flag5 = 5;
			}
			else if (flag3 == 0) {
				value.push_back("Fizz");
				flag3 = 3;
			}
			else if (flag5 == 0) {
				value.push_back("Buzz");
				flag5 = 5;
			}
			else {
				char temp[15];
				sprintf_s(temp,"%i", i);
				value.push_back(temp);
			}
			flag3--;
			flag5--;
		}
		return value;
	}
};



int main(void)
{	
	Solution a;
	ioOperate io;
	vector<int> in;
	vector<string> out;
	io.read(in);
	out = a.fizzBuzz(in[0]);
	io.write(out);
	return 0;
}