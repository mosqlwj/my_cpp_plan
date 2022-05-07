//
// Created by LWJ on 2021/9/9.
//

#include "../include/leetcode.h"

class Solution {
public:
    // 本题使用bfs在合适不可
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0)
                    result = node->val;
                if (node->left)  que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};