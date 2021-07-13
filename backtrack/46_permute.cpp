#include "../leetcode.h"

//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> path;
//        backtrack(nums, path, res);
//        return res;
//    }
//
//
//    void backtrack(vector<int>& nums, vector<int>& tack, vector<vector<int>>& res) {
//        if (tack.size() == nums.size()) {
//            res.push_back(tack);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (::find(tack.begin(), tack.end(), nums[i]) != tack.end()) {
//                continue;
//            }
//            tack.push_back(nums[i]);
//            backtrack(nums, tack, res);
//            tack.pop_back();
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        map<int, bool> visited;
        vector<int> output;
        for (auto elem : nums) {
            visited[elem] = false;
        }
        backtrack(nums, result, visited, output);
        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& result, map<int, bool>& visited, vector<int>& output) {
        if (output.size() == nums.size()) {
            result.push_back(output);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[nums[i]]) {
                output.push_back(nums[i]);
                visited[nums[i]] = true;
                backtrack(nums, result, visited, output);
                output.pop_back();
                visited[nums[i]] = false;
            }
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    for (auto elems : res) {
        for (auto e : elems) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}