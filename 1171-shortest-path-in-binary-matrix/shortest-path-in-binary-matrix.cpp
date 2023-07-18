class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = 1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            int dist = dp[row][col];
            
            if (row == n - 1 && col == n - 1)
                return dist;
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newRow = row + i;
                    int newCol = col + j;
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && dp[newRow][newCol] == INT_MAX) {
                        q.push({newRow, newCol});
                        dp[newRow][newCol] = dist + 1;
                    }
                }
            }
        }
        
        return -1;
    }
};
