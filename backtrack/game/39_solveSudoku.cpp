#include "../../leetcode.h"


class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, board.size(), board[0].size());
    }

    // 这里返回bool，因为题目中要求找到一个解即可，不需要像组合或者排列一样遍历所有叶子节点
    bool backtrack(vector<vector<char>>& board, 
                   int rows, 
                   int cols) {
        // base case
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != '.') { // 已经填入数字
                    continue;
                }
                // 尝试0-9所有数字
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        // 如果找到解，直接返回
                        if (backtrack(board, rows, cols)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                // 遍历完0-9没有找到解
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == c ) {
                    return false;
                }
            }
        }
        return true;

    }
};