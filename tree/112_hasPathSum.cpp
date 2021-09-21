//
// Created by LWJ on 2021/9/11.
//

#include "../leetcode.h"

class Solution {
public:
    // 普通preorder DFS
    bool hasPathSum1(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        // 只有根节点
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        return hasPathSum1(root->left, targetSum - root->val) ||
               hasPathSum1(root->right, targetSum - root->val);
    }
    // 回溯
    bool backtrack(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            int sum = std::accumulate(path.begin(), path.end(), 0);
            return  sum == targetSum;
        }

        bool left = false;
        bool right = false;
        path.push_back(root->val);
        if (root->left) {
            left = backtrack(root->left, targetSum, path);
            path.pop_back();
        }
        if (root->right) {
            right = backtrack(root->right, targetSum, path);
            path.pop_back();
        }
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        return backtrack(root, targetSum, path);
    }
};