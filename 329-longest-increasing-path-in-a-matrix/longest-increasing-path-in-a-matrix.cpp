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
        int ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
        if(isValid(i-1,j,grid) && grid[i][j] < grid[i-1][j]){
            if(dp[i-1][j] != -1)
        ans1 = 1+ dp[i-1][j];
        else
        ans1 = 1+ solve(i-1,j,grid,dp);
        }
       if(isValid(i+1,j,grid) && grid[i][j] < grid[i+1][j]){
            if(dp[i+1][j] != -1)
        ans2 = 1+ dp[i+1][j];
        else
        ans2 = 1+ solve(i+1,j,grid,dp);
        }
        if(isValid(i,j+1,grid) && grid[i][j] < grid[i][j+1]){
            if(dp[i][j+1] != -1)
        ans3 = 1+ dp[i][j+1];
        else
        ans3 = 1+ solve(i,j+1,grid,dp);
        }
        if(isValid(i,j-1,grid) && grid[i][j] < grid[i][j-1]){
            if(dp[i][j-1] != -1)
        ans4 = 1+ dp[i][j-1];
        else
        ans4 = 1+ solve(i,j-1,grid,dp);
        }
        return dp[i][j] = max(max(ans1,ans2),max(ans3,ans4));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
            ans = max(ans,solve(i,j,matrix,dp));
        }
        }
        return ans+1;
    }
};