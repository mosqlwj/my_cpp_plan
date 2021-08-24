//
// Created by LWJ on 2021/8/24.
//
#include "../leetcode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return  dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& preorder, int pb, int pe, vector<int>& inorder, int ib, int ie) {
        // 1. base case
        if (pb > pe || ib > ie) {
            return nullptr;
        }
        // 2. get root value
        int tmp = preorder[pb];
        int index = ib;
        for (int i = ib; i <= ie; i++) {
            if (inorder[i] == tmp) {
                index = i;
                break;
            }
        }
        // 3. dfs
        TreeNode* root = new TreeNode(tmp);
        int count = index - ib;
        root->left = dfs(preorder, pb + 1, pb + count, inorder, ib, index - 1);
        root->right = dfs(preorder, pb + count + 1, pe, inorder, index + 1, ie);
        return root;
    }
};