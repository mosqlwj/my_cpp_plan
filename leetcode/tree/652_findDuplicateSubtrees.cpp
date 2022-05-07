//
// Created by LWJ on 2021/8/26.
//
#include "../include/leetcode.h"

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mem;
        string subtree = dfs(root, res, mem);
        std::cout << subtree << std::endl;
        return res;
    }

    // 后序遍历对二叉树进行序列化。中序遍历则不行，无法保证子树的结构一致。
    string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& mem) {
        if (root == nullptr) {
            return "#";
        }
        string left = dfs(root->left, res, mem);
        string right = dfs(root->right, res, mem);
        string subtree = left + "," + right + "," + to_string(root->val);
        if (mem[subtree] == 1) {
            res.push_back(root);
        }
        mem[subtree] += 1;
        return subtree;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;

    TreeNode* node3 = new TreeNode(4);
    node1->left = node3;

    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(4);
    node2->left = node4;
    node2->right = node5;

    TreeNode* node6 = new TreeNode(4);
    node4->left = node6;

    Solution().findDuplicateSubtrees(root);
    return 0;
}