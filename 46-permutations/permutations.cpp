class Solution {
public:
    void solve(vector<int>& nums, vector<int>& row, vector<vector<int>>& ans, vector<bool>& used) {
        if (row.size() == nums.size()) {
            ans.push_back(row);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                row.push_back(nums[i]);
                solve(nums, row, ans, used);
                row.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> row;
        vector<bool> used(nums.size(), false);
        solve(nums, row, ans, used);
        return ans;
    }
};
