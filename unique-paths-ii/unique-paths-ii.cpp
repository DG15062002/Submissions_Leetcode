class Solution {
public:
    bool isValid(int i, int j,vector<vector<int>> &obstacleGrid){
        if(i < 0 || i >= obstacleGrid.size() || j < 0  || j >= obstacleGrid[i].size())
        return false;
        return true;
    }
    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        int temp1 = 0,temp2 = 0,ans = 0;
         if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0){
            return dp[i][j] = 1;
        } 
        if(obstacleGrid[i][j] != 1){
        if(isValid(i,j-1,obstacleGrid) && isValid(i-1,j,obstacleGrid) && obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] != 1){
        ans = max(ans, solve(i,j-1,obstacleGrid,dp)+solve(i-1,j,obstacleGrid,dp));
        }
        if(isValid(i,j-1,obstacleGrid) && obstacleGrid[i][j-1] != 1){
        ans = max(ans, solve(i,j-1,obstacleGrid,dp));
        }
        if(isValid(i-1,j,obstacleGrid) && obstacleGrid[i-1][j] != 1){
        ans = max(ans,solve(i-1,j,obstacleGrid,dp));
        }
        }
        return dp[i][j] = ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
         if(n ==1 && m == 1) return 1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};