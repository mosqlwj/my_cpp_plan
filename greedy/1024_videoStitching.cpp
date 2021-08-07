//
// Created by liwenjie on 2021/8/7.
//
#include "../leetcode.h"

class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        if (time == 0)
            return 0;
        if (clips.empty())
            return 0;
        sort(clips.begin(), clips.end(), cmp);
        int count = 0;
        int cur_end = 0, next_end = 0;
        int n = clips.size();
        int i = 0;
        // 区间处理容易出错
        while (i < n && clips[i][0] <= cur_end) {
            while (i < n && clips[i][0] <= cur_end) {
                next_end = max(next_end, clips[i][1]);
                i++;
            }
            cur_end = next_end;
            count++;

            if (cur_end >= time) {
                return count;
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> clips = {{0, 2}, {4, 8}};
    int res = Solution().videoStitching(clips, 10);
    cout << res << endl;
    return 0;
}