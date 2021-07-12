//
// Created by LWJ on 2021/7/12.
//
#include "../leetcode.h"

class Solution {
public:
    // 1. recursion
//    int fib1(int n) {
//        if (n == 0 || n == 1)
//            return 1;
//        return fib1(n - 1) + fib1(n - 2);
//    }

    // 2. memo
//    int fib(int n) {
//        if (n < 1) return 0;
//        vector<int> memo(n + 1, 0);
//        return helper(memo, n);
//    }
//
//    int helper(vector<int>& memo, int n) {
//        if (n == 1 || n == 2) return 1;
//        if (memo[n] != 0) return memo[n];
//        memo[n] = helper(memo, n - 1) + helper(memo, n-2);
//        return memo[n];
//    }

    // dp
    int fib(int n) {
        if (n < 1) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n + 1, 0);
        // base case
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

};

int main() {
    cout << Solution().fib(5) << endl;
    return 0;
}