//
// Created by LWJ on 2021/8/26.
//
#include "../leetcode.h"

class Solution {
public:
    int numTrees(int n) {
//        return dfs(1, n);
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, 0));
        int res = dp(1, n, mem);
        return res;
    }

    // 闭区间[lo, hi]
    // [1, 2, 3, 4, 5]
    //        i = 3
    // [1, 2],  [4, 5]
    int dfs(int lo, int hi) {
        if (lo > hi) {
            return 1;
        }

        int res = 0;
        for (int i = lo; i <= hi; i++) {
            int left = dfs(lo, i - 1);
            int right = dfs(i + 1, hi);
            res += left * right;
        }
        return res;
    }

    int dp(int lo, int hi, vector<vector<int>>& mem) {
        if (lo > hi)
            return 1;
        if (mem[lo][hi] != 0)
            return mem[lo][hi];

        int res = 0;
        for (int i = lo; i <= hi; i++) {
            int left = dp(lo, i - 1, mem);
            int right = dp(i + 1, hi, mem);
            res += left * right;
        }
        mem[lo][hi] = res;
        return res;
    }
};

int main() {
    int res = Solution().numTrees(3);
    cout << res << endl;
    return 0;
}