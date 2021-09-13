
#include "../leetcode.h"

class Solution {
public:
    // 中序遍历
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        bool left = isValidBST(root->left);
        // 必须小于
        if (pre != nullptr && pre->val >= root->val)
            return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};