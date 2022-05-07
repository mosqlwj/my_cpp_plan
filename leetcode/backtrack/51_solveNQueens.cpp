#include "../include/leetcode.h"


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backtrack(n, 0, board, res);
        return res;
    }

    void backtrack(int n, 
                   int row,
                   vector<string> &board, 
                   vector<vector<string>> &res) {
        // base case:叶子节点
        if (n == row) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col))
                continue;
            
            board[row][col] = 'Q';
            backtrack(n, row + 1, board, res);
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string> &board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; 
                i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
                i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
