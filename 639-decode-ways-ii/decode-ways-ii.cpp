class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;
        
        long dp[n + 1];
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                dp[i] = 9 * dp[i + 1] % MOD;
                if (i + 1 < n) {
                    if (s[i + 1] == '*') {
                        dp[i] = (dp[i] + 15 * dp[i + 2]) % MOD;
                    } else if (s[i + 1] >= '0' && s[i + 1] <= '6') {
                        dp[i] = (dp[i] + 2 * dp[i + 2]) % MOD;
                    } else {
                        dp[i] = (dp[i] + dp[i + 2]) % MOD;
                    }
                }
            } else if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < n) {
                    if (s[i + 1] == '*') {
                        if (s[i] == '1') {
                            dp[i] = (dp[i] + 9 * dp[i + 2]) % MOD;
                        } else if (s[i] == '2') {
                            dp[i] = (dp[i] + 6 * dp[i + 2]) % MOD;
                        }
                    } else {
                        int num = stoi(s.substr(i, 2));
                        if (num >= 10 && num <= 26) {
                            dp[i] = (dp[i] + dp[i + 2]) % MOD;
                        }
                    }
                }
            }
        }
        
        return dp[0];
    }
};
