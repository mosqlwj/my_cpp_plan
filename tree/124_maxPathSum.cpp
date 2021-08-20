//
// Created by LWJ on 2021/8/20.
//
#include "../leetcode.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        postOrderDFS(root, res);
        return res;
    }

    int postOrderDFS(TreeNode* root, int& res) {
        if (root == nullptr)
            return 0;

        int left = max(0, postOrderDFS(root->left, res));
        int right = max(0, postOrderDFS(root->right, res));

        res = max(res, root->val + left + right);
        return root->val + max(left, right);
    }
};