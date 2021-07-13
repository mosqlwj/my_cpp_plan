//
// Created by liwenjie on 2021/5/13.
//
#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> output;
        backtrack(nums, result, visited, output);
        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<bool>& visited, vector<int>& output) {
        if (output.size() == nums.size()) {
            result.push_back(output);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;
            output.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, result, visited, output);
            output.pop_back();
            visited[i] = false;

        }
    }
};

int main() {
    vector<int> nums{1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (auto elems : res) {
        for (auto e : elems) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}