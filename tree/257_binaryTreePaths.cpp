//
// Created by LWJ on 2021/9/7.
//
#include "../leetcode.h"

class Solution {
public:
    // 思路：dfs前序遍历，暗含回溯的思想
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
            return res;
        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode* root, string path, vector<string>& res) {
        // 此处root != nullptr
        if (root == nullptr)
            return;
        path += to_string(root->val);
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        path += "->";
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        return;
    }
};