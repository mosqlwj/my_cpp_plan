//
// Created by liwenjie on 2021/8/7.
//

#include "../include/leetcode.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
            return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int count = 1;
        int x_end = points[0][1];
        for (const auto& elem : points) {
            if (elem[0] > x_end) {
                count++;
                x_end = elem[1];
            }
        }
        return count;
    }

};