//
// Created by LWJ on 2021/9/7.
//
#include "../leetcode.h"

class Solution {
public:
    // 思路：dfs前序遍历，暗含回溯的思想
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
            return res;
        dfs(root, "", res);
        return res;
    }
    // 这里传入string path的copy，每次递归是都是一份新的path副本
    // 改进策略：使用回溯方法，传入string的引用，但是需要在递归后将path恢复之前的状态。
    // 回溯其实就是在穷举。
    void dfs(TreeNode* root, string path, vector<string>& res) {
        // 此处root != nullptr
        // 处理左子树或者右子树为空的情况
        //    1
        //  /   \
        //  2   null
        if (root == nullptr)
            return;
        path += to_string(root->val);
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        path += "->";
        dfs(root->left, path, res);
        dfs(root->right, path, res);
        return;
    }
};