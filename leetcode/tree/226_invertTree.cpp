//
// Created by LWJ on 2021/8/20.
//

#include "../include/leetcode.h"

class Solution {
public:
    // dfs
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    // bfs
    TreeNode* invertTree2(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }

        return root;
    }
};