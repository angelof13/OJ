#ifndef __PARAMETER
#define __PARAMETER
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* pre;
	ListNode* next;
	ListNode() :val(0), pre(nullptr), next(nullptr) {}
	ListNode(int x) : val(x), pre(nullptr), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Parameter {
public:
	bool b1=false;
	int i1=0, i2=0, i3=0;
	double d1=0, d2=0, d3=0;
	char c1=0, c2=0, c3=0;
	string s1, s2, s3;
	vector<int> vi1, vi2, vi3;
	vector<vector<int>> vvi1, vvi2, vvi3;
	vector<char> vc1;
	vector<string> vs1, vs2, vs3;
	vector<vector<string>> vvs1, vvs2, vvs3;
	vector<ListNode*> vh1,vh2;
	ListNode* head1=nullptr, *head2 = nullptr, *head3 = nullptr;
	TreeNode* root1 = nullptr, *root2 = nullptr, *root3 = nullptr;
};
#endif
#pragma once
