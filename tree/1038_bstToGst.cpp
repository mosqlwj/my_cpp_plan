//
// Created by LWJ on 2021/8/29.
//
#include "../leetcode.h"

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