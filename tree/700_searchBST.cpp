//
// Created by LWJ on 2021/9/12.
//
#include "../leetcode.h"
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        if (val == root->val) {
            return root;
        } else if (val < root->val) {
            return searchBST(root->left, val);
        } else  {
            return searchBST(root->right, val);
        }
    }
};