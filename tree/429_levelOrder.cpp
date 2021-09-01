//
// Created by LWJ on 2021/9/1.
//
#include "../leetcode.h"
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                tmp.push_back(node->val);

                for (const auto& curr_node : node->children) {
                    if (curr_node) {
                        que.push(curr_node);
                    }
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};