//
// Created by LWJ on 2021/9/1.
//
#include "../include/leetcode.h"

class Solution {
public:
    // 层次遍历，获取每行的最大值
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int max_val = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->val > max_val) {
                    max_val = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(max_val);
        }
        return res;
    }
};