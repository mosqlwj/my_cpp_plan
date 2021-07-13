#include "../leetcode.h"


class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, res);
        return res;
    }

    
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backtrack(nums, i+1, path, res);
            path.pop_back();
        }

    }
};

int main() {
    vector<int> nums{1, 2, 2};
    vector<vector<int>> res =  Solution().subsetsWithDup(nums);
    for (auto elems : res) {
        for (auto e : elems) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}