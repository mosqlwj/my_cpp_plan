//
// Created by liwenjie on 2021/5/21.
//

#include "../leetcode.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> use(n + 1, false);
        string res;
        backtrack(use, res, n, k, 0);
        return res;
    }
    void backtrack(vector<bool>& used, string& res, int n, int k, int index) {
        // index 表示递归的层次
        if (index == n)
            return;
        //计算当前分支下，排列的总个数。
        int cnt = fac(n - 1 - index);
        for (int i = 1; i <= n; i++) {
            if (used[i])
                continue;
            // 如果前一个分支排列的个数小于k，则剪掉该分支。
            if (cnt < k) {
                k -= cnt;
                continue;
            }

            res += to_string(i);
            used[i] = true;
            backtrack(used, res, n, k, index+1);

        }
    }
    // 计算当前分支下，排列的总个数。
    int fac(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};