#ifndef __PARAMETER
#define __PARAMETER
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};

class Parameter {
public:
	int i1, i2, i3;
	char c1, c2, c3;
	string s1, s2, s3;
	vector<int> vi1, vi2, vi3;
	vector<vector<int>> vvi1, vvi2, vvi3;
	vector<string> vs1, vs2, vs3;
	ListNode* head = new ListNode();
};
#endif
#pragma once
