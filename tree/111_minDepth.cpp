//
// Created by LWJ on 2021/9/1.
//

#include "../leetcode.h"

class Solution {
public:
    // DFS
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int left  = minDepth(root->left);
        int right = minDepth(root->right);
        if (root->left == nullptr || root->right == nullptr)
            return left + right + 1;
        return min(left, right) + 1;
    }
    // BFS
    int minDepth2(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // 记录最小深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};