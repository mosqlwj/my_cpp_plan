//
// Created by LWJ on 2021/9/7.
//

#include "../leetcode.h"

class Solution {
public:
    // dfs
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    // bfs

};