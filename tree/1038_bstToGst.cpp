//
// Created by LWJ on 2021/8/29.
//
#include "../leetcode.h"
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
//};
class Solution {
public:
    int sum = 0;
    // 和538题一样
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
};