
#include "../include/leetcode.h"

class Solution {
public:
    
    // p和q，要么在root的两异侧，要么都在left或者right同侧，或者不存在
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        // 
        if (root == p || root == q) 
            return root;
        // 左侧寻找p或者q
        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        // 右侧寻找p或者q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;
        
        if (right == nullptr)
            return left;
        // left != nullptr && right != nullptr
        return root;
        
    }
};