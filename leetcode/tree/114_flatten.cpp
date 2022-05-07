//
// Created by LWJ on 2021/8/21.
//
#include "../include/leetcode.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;
        // wrong way
        // left->right = right;
        // right way
        TreeNode* p = root;
        while (p->right) {
            p = p->right;
        }
        p->right = right;
    }
};
