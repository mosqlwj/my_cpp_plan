//
// Created by liwenjie on 2021/8/27.
//
#include "../include/leetcode.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = dfs(1, n);
        return res;
    }

    vector<TreeNode*> dfs(int lo, int hi) {
        vector<TreeNode*> res;
        if (lo > hi) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = lo; i <= hi; i++) {
            vector<TreeNode*> lefts = dfs(lo, i - 1);
            vector<TreeNode*> rights = dfs(i + 1, hi);
            for (auto& left : lefts) {
                for (auto& right : rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution().generateTrees(3);
    return 0;
}