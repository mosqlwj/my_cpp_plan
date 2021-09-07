//
// Created by LWJ on 2021/9/1.
//

#include "../leetcode.h"

class Solution {
public:
    // DFS 详细代码：根左右
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int left  = minDepth(root->left);
        int right = minDepth(root->right);
        // 当左子树为空，右子树不为空时，返回右子树最小深度 + 1
        int res = 0;
        if (root->left == nullptr && root->right != nullptr) {
            res = right + 1;
        }
        // 当右子树为空，左子树不为空时，返回左子树最小深度 + 1
        if (root->left != nullptr && root->right == nullptr) {
            res = left + 1;
        }
        // 当左右子树都不为空时
        if (root->left && root->right) {
            res = min(left, right) + 1;
        }
        return res;
    }
    // 简化代码
    int minDepth1_2(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int left  = minDepth1_2(root->left);
        int right = minDepth1_2(root->right);
        if (root->left == nullptr || root->right == nullptr)
            return left + right + 1;
        return min(left, right) + 1;
    }
    // 错误代码.
    // 错误原因在于：最小深度是从根节点到最近叶子节点的最短路径上的节点数量，是叶子节点。
    //
    int minDepth1_1(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = minDepth1_1(root->left);
        int right = minDepth1_1(root->right);
        return min(left, right) + 1;
    }


    // BFS
    int minDepth2(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // 记录最小深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};