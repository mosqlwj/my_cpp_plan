//
// Created by LWJ on 2021/8/29.
//
#include "../leetcode.h"

class Solution {
public:
    int count = 0;
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
    // 中序遍历
    void dfs(TreeNode* root, int k) {
        if (root == nullptr)
            return;
        dfs(root->left, k);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }

    void dfs2(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        dfs2(root->left, res);
        res.push_back(root->val);
        dfs2(root->right, res);
    }
};