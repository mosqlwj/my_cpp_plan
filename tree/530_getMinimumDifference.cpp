
#include "../leetcode.h"

class Solution {
public:
    int res = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return 0;
        TreeNode* pre = nullptr;
        dfs_bst(root, pre);
        return res;
    }
    // 注意这里的pre必须是引用，或者双指针
    void dfs_bst(TreeNode* root, TreeNode* &pre) {
        if (root == nullptr)
            return ;
        
        dfs_bst(root->left, pre);
        if (pre != nullptr) {
            res = min(res, root->val - pre->val);
        }
        pre = root;
        dfs_bst(root->right, pre);

    }
};