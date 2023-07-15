class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int totalSum = 0;
        int maxNum = 0;
        
        for (int num : matchsticks) {
            totalSum += num;
            maxNum = max(maxNum, num);
        }
        
        if (totalSum % 4 != 0 || maxNum > totalSum / 4) {
            return false; // Invalid partitioning is not possible
        }
        
        int targetSum = totalSum / 4;
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) {
                continue; // Invalid mask
            }
            
            for (int i = 0; i < n; i++) {
                int nextMask = mask | (1 << i);
                
                if (dp[mask] + matchsticks[i] <= targetSum && dp[nextMask] == -1) {
                    dp[nextMask] = (dp[mask] + matchsticks[i]) % targetSum;
                }
            }
        }
        
        return dp[(1 << n) - 1] == 0;
    }
};