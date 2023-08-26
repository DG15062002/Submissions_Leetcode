class Solution {
public:
    bool isSquareful(long long num) {
        long long root = sqrt(num);
        return root * root == num;
    }

    void backtrack(vector<int>& nums, int index, vector<bool>& used, int prev, int& count) {
        if (index == nums.size()) {
            count++;
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            
            if (index == 0 || isSquareful(prev + nums[i])) {
                used[i] = true;
                backtrack(nums, index + 1, used, nums[i], count);
                used[i] = false;
            }
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<bool> used(nums.size(), false);
        backtrack(nums, 0, used, 0, count);
        return count;
    }
};
