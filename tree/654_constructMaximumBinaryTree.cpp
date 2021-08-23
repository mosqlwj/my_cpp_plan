//
// Created by liwenjie on 2021/8/23.
//
#include "../leetcode.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums , int left, int right) {
        if (left > right)
            return nullptr;
        int index = left;
        int num = nums[left];
        for (int i = left; i <= right; i++) {
            if (nums[i] > num) {
                index = i;
                num = nums[i];
            }
        }
        TreeNode* root = new TreeNode(nums[index]);
        root->left = build(nums, left, index - 1);
        root->right = build(nums, index + 1, right);
        return root;
    }
};