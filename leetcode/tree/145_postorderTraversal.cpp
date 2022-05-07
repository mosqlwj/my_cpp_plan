//
// Created by LWJ on 2021/8/31.
//
#include "../include/leetcode.h"

class Solution {
public:
    // 前序遍历是根左右——>根右左——>左右根——>后续遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (nullptr == root) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

};
