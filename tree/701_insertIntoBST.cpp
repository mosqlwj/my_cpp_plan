#include "../leetcode.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;

    }
};