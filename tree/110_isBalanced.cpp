//
// Created by LWJ on 2021/9/7.
//
#include "../leetcode.h"

class Solution {
public:
    // 思路：dfs
    // 左右子树的高度差大于1时返回-1，否则就正常计算树的高度
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (left == -1)
            return -1;
        if (right == -1)
            return -1;

        int res = 0;
        if (abs(left - right) > 1)
            res = -1;
        else
            res = max(left, right) + 1;
        return res;
    }
};
