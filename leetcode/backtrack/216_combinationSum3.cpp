#include "../include/leetcode.h"

class Solution {
public:
   // 这题的思路和77题一样，组合不考虑顺序的问题
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        int sum = 0;
        backtrack(k, n, sum, 1, path, res);
        return res;
    }

    void backtrack(int k, 
                   int n, 
                   int &sum, 
                   int start_index, 
                   vector<int>& path, 
                   vector<vector<int>>& res) {

        if (k == path.size()) {
            // 达到k个数，且数字之和等于n
            if (sum == n) {
                res.push_back(path);
                return;
            } else {
            // 达到k个数，但是数字之和不等于n
                return;
            }
        }
        // i = start_index控制树每层遍历的宽度
        for (int i = start_index; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            // i + 1 控制下一层遍历的起始位置
            backtrack(k, n, sum, i + 1, path, res);
            sum -= i;
            path.pop_back();
        }
    }
};