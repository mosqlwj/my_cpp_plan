#include "../leetcode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return dfs(root->left, root->right);
    }
    // dfs
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }

        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    // bfs
    bool bfs(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        if (root->left == nullptr && root->right == nullptr)
            return true;
        
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();

            if (left == nullptr && right == nullptr)
                continue;
            
            if (left == nullptr || right == nullptr)
                return false;
            
            if (left->val != right->val) 
                return false;
            
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};

int main() {
    cout << "hello" << endl;
    return 0;
}