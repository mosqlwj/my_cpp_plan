
#include "../include/leetcode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        if (p->val < root->val && q->val > root->val)
            return root;
        
        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        
        return root;
    }
};