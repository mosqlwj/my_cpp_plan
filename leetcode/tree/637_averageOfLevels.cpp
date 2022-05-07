//
// Created by LWJ on 2021/9/1.
//
#include "../include/leetcode.h"

class Solution {
public:
    // 计算每层的平均值， 层次遍历
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0.0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(sum / size);
        }
        return res;
    }
};