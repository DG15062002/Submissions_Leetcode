#define MOD 1000000007

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> powers(n, 1);
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }

        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + powers[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
