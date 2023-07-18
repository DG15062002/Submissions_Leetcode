#define MOD 1000000007
class Solution {
public:
    bool isValid(int i, int j,vector<vector<int>> &grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return false;
        return true;
    }
    int solve(int i, int j, int &n, int &m, int &k,
    vector<vector<int>> &grid,vector<vector<vector<int>>> &dp, int sum){
        if(!isValid(i,j,grid)) return 0;
        if(i == n-1 && j == m-1){
        sum = (sum + grid[i][j])%k;
        if(sum % k == 0) return 1;
        return 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        return dp[i][j][sum%k] = (solve(i+1,j,n,m,k,grid,dp,(sum+grid[i][j])%k)+solve(i,j+1,n,m,k,grid,dp,(sum+grid[i][j])%k))%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return solve(0,0,n,m,k,grid,dp,0);
    }
};