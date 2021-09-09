//
// Created by LWJ on 2021/9/8.
//
#include "../leetcode.h"

class Solution {
public:
    // 判断是否是叶子节点
    bool isLeafNode(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
    int dfs(TreeNode* root) {
        int ans = 0;
        if (root->left) {
            if (isLeafNode(root->left)) {
                ans += root->left->val;
            } else {
                ans += dfs(root->left);
            }
        }
        if (root->right) {
            if (!isLeafNode(root->right)) {
                ans += dfs(root->right);
            }
        }
        return ans;
    }
    //思路：无论是dfs还是bfs，将树遍历一遍，找到左叶子节点
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return bfs(root);
    }

    // bfs
    int bfs(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    if (isLeafNode(node->left)) {
                        ans += node->left->val;
                    } else {
                        que.push(node->left);
                    }
                }
                if (node->right) {
                    if (!isLeafNode(node->right)) {
                        que.push(node->right);
                    }
                }
            }
        }
        return ans;
    }
};