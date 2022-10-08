#ifndef __PARAMETER
#define __PARAMETER
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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
	bool b;
	int i1, i2, i3;
	double d1, d2, d3;
	char c1, c2, c3;
	string s1, s2, s3;
	vector<int> vi1, vi2, vi3;
	vector<vector<int>> vvi1, vvi2, vvi3;
	vector<char> vc1;
	vector<string> vs1, vs2, vs3;
	vector<vector<string>> vvs1, vvs2, vvs3;
	vector<ListNode*> vh1,vh2;
	ListNode* head1, head2, head3;
	TreeNode* root1, root2, root3;
};
#endif
#pragma once
