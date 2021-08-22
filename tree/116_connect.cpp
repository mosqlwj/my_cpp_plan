//
// Created by LWJ on 2021/8/22.
//
#include "../leetcode.h"

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
        dfs(root);
        return root;
    }

    void dfs(Node* root) {
        if (root == NULL) {
            return;
        }

        Node* left = root->left;
        Node* right = root->right;
        while (left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        dfs(root->left);
        dfs(root->right);

    }

    void bfs(Node* root) {

    }

    void traverse(Node* root) {
        if (root == NULL)
            return;
        Node* node = root;
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
        traverse(root->left);
        // traverse(root->right);
    }
};

int main(void) {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    Node* root = Solution().connect(a);
    Solution().traverse(root);
    return 0;
}