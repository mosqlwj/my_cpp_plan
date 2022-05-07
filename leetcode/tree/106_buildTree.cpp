//
// Created by liwenjie on 2021/8/25.
//
#include "../include/leetcode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& inorder, int ib, int ie, vector<int>& postorder, int pb, int pe) {

        // base case
        if (ib > ie || pb > pe) {
            return nullptr;
        }
        int index = 0;
        int tmp = postorder[pe];
        TreeNode* root = new TreeNode(tmp);
        for (int i = ib; i <= ie; i++) {
            if (inorder[i] == tmp) {
                index = i;
                break;
            }
        }
        int count = index - ib;
        root->left = dfs(inorder, ib, index - 1, postorder, pb, pb + count - 1);
        root->right = dfs(inorder, index + 1, ie, postorder,  pb + count, pe - 1);
        return root;
    }
};