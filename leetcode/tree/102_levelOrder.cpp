//
// Created by LWJ on 2021/8/31.
//
#include "../include/leetcode.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
