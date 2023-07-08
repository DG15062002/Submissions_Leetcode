class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
         int n = types.size();
    int mod = 1000000007;
    vector<int> dp(target + 1,0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int count = types[i][0];
        int mark = types[i][1];
        for (int j = target; j >= mark; j--) {
            for (int k = 1; k <= count && j - k * mark >= 0; k++) {
                dp[j] = (dp[j] + dp[j - k * mark]) % mod;
            }
        }
    }
    return dp[target];  
    }
};