//
// Created by LWJ on 2021/8/29.
//
#include "../include/leetcode.h"

class Solution {
public:
    int sum = 0;
    // 反向中序遍历，即降序
    TreeNode* convertBST(TreeNode* root) {
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