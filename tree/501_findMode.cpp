#include "../leetcode.h"

class Solution {
public:
    vector<int> res;
    int count = 0;
    int max_count = 0;
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr)
            return res;
        TreeNode* pre = nullptr;
        dfs_bst(root, pre);
        return res;
    }
     // 中序遍历：注意这里的pre必须是引用，或者双指针
    void dfs_bst(TreeNode* root, TreeNode* &pre) {
        if (root == nullptr)
            return ;
        
        dfs_bst(root->left, pre);
        if (pre == nullptr) {
            // 第一个元素
            count = 1;
        } else {
            if (pre->val == root->val) { // 如果当前元素和pre相同
                count++;
            } else {
                count = 1;  // 元素不同，count置为1
            }
        }
        pre = root;
        // 保存众数
        if (count == max_count) {
            res.push_back(pre->val);
        }

        if (count > max_count) {
            max_count = count;
            res.clear();
            res.push_back(pre->val);
        }
        dfs_bst(root->right, pre);

    }
};