#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int size1 = nums1.size(), size2 = nums2.size(),
			n1 = 0, n2 = 0,
			middle1 = 0, middle2 = 0,
			middle = (size1 + size2) / 2,
			flag = (size1 + size2) & 1;
		if (size1 == 0) 
		{
			if (size2 & 1) 
			{
				return nums2[size2 / 2];
			}
			else 
			{
				return (nums2[size2 / 2] + nums2[size2 / 2 - 1]) * 1.0 / 2;
			}
		}
		if (size2 == 0)
		{
			if (size1 & 1)
			{
				return nums1[size1 / 2];
			}
			else
			{
				return (nums1[size1 / 2] + nums1[size1 / 2 - 1]) * 1.0 / 2;
			}
		}
		for (int i = 0; i <= middle; i++)
		{
			middle2 = middle1;
			if (n1 < size1 && n2 < size2)
			{
				nums1[n1] < nums2[n2] ? middle1 = nums1[n1++] : middle1 = nums2[n2++];
			}
			else if (n1 == size1 && n2 < size2)
			{
				middle1 = nums2[n2++];
			}
			else if (n2 == size2 && n1 < size1)
			{
				middle1 = nums1[n1++];
			}
		}
 		if (flag) 
		{
			return middle1;
		}
		else 
		{
			return (middle2 + middle1)*1.0 / 2;
		}
	}
};

int main(void)
{
	vector<int> t1, t2;
	t1.push_back(2);
	t1.push_back(3);
	t1.push_back(4);
	t2.push_back(1);
	Solution a;
	cout << a.findMedianSortedArrays(t1,t2) <<endl;
	system("pause");
	return 0;
}