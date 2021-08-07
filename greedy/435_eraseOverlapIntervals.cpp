//
// Created by liwenjie on 2021/8/7.
//
#include "../leetcode.h"

class Solution {
public:
    // 贪心算法
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 1;
        int x_end = intervals[0][1];
        for (const auto& elem : intervals ) {
            int start = elem[0];
            if (start >= x_end) {
                count++;
                x_end = elem[1];
            }
        }
        return intervals.size() -  count;
    }
};