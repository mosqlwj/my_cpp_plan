//
// Created by LWJ on 2021/7/12.
//

#ifndef MY_LEETCODE_PLAN_LEETCODE_H
#define MY_LEETCODE_PLAN_LEETCODE_H
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#endif //MY_LEETCODE_PLAN_LEETCODE_H
