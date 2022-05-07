//
// Created by LWJ on 2021/9/1.
//

#include "../include/leetcode.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
    // 层次遍历，记录同层次前继节点
    void bfs(Node* root) {
        if (root == nullptr) {
            return;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* pre_node = nullptr;
            for (int i = 0; i < size; i++) {
                if ( 0 == i) {
                    pre_node = que.front();
                    que.pop();

                } else {
                    Node* node = que.front();
                    que.pop();
                    pre_node->next = node;
                    pre_node = node;

                }
                if (pre_node->left) {
                    que.push(pre_node->left);
                }
                if (pre_node->right) {
                    que.push(pre_node->right);
                }
            }
        }
    }

};