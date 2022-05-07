#include "../include/leetcode.h"

class Solution {
public:
    // 对于有序数组构建BST，直接将数组区间从中间进行划分
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        return buildBST(nums, 0 , nums.size() - 1);
    }
    // 左闭，右闭
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // 空区间：base case
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};