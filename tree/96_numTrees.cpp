//
// Created by LWJ on 2021/8/26.
//

class Solution {
public:
    int numTrees(int n) {
        return dfs(1, n);
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
};