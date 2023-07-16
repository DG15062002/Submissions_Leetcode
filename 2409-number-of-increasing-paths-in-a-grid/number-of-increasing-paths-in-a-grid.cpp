#define MOD 1000000007
class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>> &grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return false;
        return true;
    }
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(!isValid(i,j,grid)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
        if(isValid(i-1,j,grid) && grid[i][j] < grid[i-1][j]){    
        if(dp[i-1][j] != -1)
        ans1 = dp[i-1][j];
        else
        ans1 = solve(i-1,j,grid,dp);
        }
       if(isValid(i+1,j,grid) && grid[i][j] < grid[i+1][j]){
        if(dp[i+1][j] != -1)
        ans2 = dp[i+1][j];
        else
        ans2 = solve(i+1,j,grid,dp);
        }
        if(isValid(i,j+1,grid) && grid[i][j] < grid[i][j+1]){
            if(dp[i][j+1] != -1)
        ans3 = dp[i][j+1];
        else
        ans3 = solve(i,j+1,grid,dp);
        }
        if(isValid(i,j-1,grid) && grid[i][j] < grid[i][j-1]){
        if(dp[i][j-1] != -1)
        ans4 = dp[i][j-1];
        else
        ans4 = solve(i,j-1,grid,dp);
        }
        return dp[i][j] = (1+ans1+ans2+ans3+ans4) % MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        long long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
            ans= (ans + solve(i,j,grid,dp)) % MOD;
        }
        }
        return ans;
    }
};