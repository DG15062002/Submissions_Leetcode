class Solution {
public:
//     int numSubsequences(vector<int>& nums, int target) {
//     int n = nums.size();
//     vector<int> dp(target + 1, 0);
//     dp[0] = 1;

//     for (int num : nums) {
//         for (int i = target; i >= num; i--) {
//             dp[i]+=dp[i - num] ;
//         }
//     }

//     return dp[target];
// }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};