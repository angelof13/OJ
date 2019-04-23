#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> test(vector<int>& nums1, vector<int>& nums2) 
	{
		int size = nums1.size();
		vector<int> temp;
		vector<vector<int>> value;
		value.push_back(temp);
		value.push_back(temp);
		for (int i = 0; i < size; i++)
		{
			value[0].push_back(nums1[i] * nums2[i]);
			value[1].push_back(nums1[i] + nums2[i]);
		}
		return value;
	}
};

int main(void)
{	
	Solution a;
	int in_temp;
	vector<int> in_o, out_o;
	vector<vector<int>> in_t, out_t;
	ifstream main_in("main_in.txt");
	ofstream main_out("main_out.txt");
	string stemp;
	while(getline(main_in, stemp))
	{
		stringstream ss;
		ss << stemp;
		while(!ss.eof())
		{
			ss >> in_temp;
			in_o.push_back(in_temp);
		}
		in_t.push_back(in_o);
		in_o.clear();
	}
	out_t = a.test(in_t[0], in_t[1]);
	for(auto i : out_t)
	{
		for(auto j : i)
			main_out << j << ' ';
		main_out << endl;
	}
	return 0;
}