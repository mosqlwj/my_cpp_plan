//
// Created by LWJ on 2021/9/1.
//
#include "../include/leetcode.h"

class Solution {
public:
    // dfs
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
    // bfs
    int maxDepth2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return depth;
    }
};