#include "../leetcode.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. 没有找到节点，返回NULL
        if (root == nullptr)
            return nullptr;
        // 2. 在左子树
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
        // 3. 在右子树
            root->right = deleteNode(root->right, key);
        } else {
        // 4. 值相等：存在四种情况
            // 4.1 当前节点的左右子树都为空
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            // 4.2 左子树空，右子树不为空
            if (root->left == nullptr && root->right != nullptr)
                return root->right;
            // 4.3 左子树不为空，右子树空    
            if (root->left != nullptr && root->right == nullptr)
                return root->left;
            // 4.4 左右子树都不为空，寻找右子树最左侧的节点替代当前节点值
            if (root->left != nullptr && root->right != nullptr) {
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                // 值替换，然后在右子树继续查找替代值进行删除
                root->val = cur->val;
                root->right = deleteNode(root->right, cur->val);
            }
        }
        return root;
    }
};