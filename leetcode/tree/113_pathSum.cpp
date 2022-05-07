//
// Created by LWJ on 2021/9/11.
//
#include "../include/leetcode.h"


class Solution {
public:
    // 回溯
    void backtrack(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {
//        if (root == nullptr)
//            return ;

        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            int sum = std::accumulate(path.begin(), path.end(), 0);
            if (sum == targetSum) {
                res.push_back(path);
            }
            return;
        }

        path.push_back(root->val);
        if (root->left) {
            backtrack(root->left, targetSum, path, res);
            path.pop_back();
        }
        if (root->right) {
            backtrack(root->right, targetSum, path, res);
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        if (root == nullptr) return res;
        backtrack(root, targetSum, path, res);
        return res;
    }
};