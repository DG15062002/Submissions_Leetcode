class Solution {
public:
    int dp[1000005][2][3];
    int mod = 1e9+7;
    long solve(int n, int a, int l) {
        if(a==2 || l==3) return 0;
        if(n==0) return 1;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
        long pr = solve(n-1,a,0)%mod;
        long ab = solve(n-1,a+1,0)%mod;
        long la = solve(n-1,a, l+1)%mod;
        return dp[n][a][l] = (pr+ab+la)%mod;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n,0,0);
    }
};