class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
       if((i==s1.size()&&j==s2.size()) && (k==s3.size())) return true; 
        if(dp[i][j]!= -1)return dp[i][j];
        if(i==s1.size()&& j< s2.size()){
            if(s3[k]==s2[j])
                return dp[i][j] = solve(s1,s2,s3,i,j+1,k+1,dp); // if s1 string gets empty
            return false;
        }
        if(i<s1.size() && j==s2.size()){
            if(s3[k]==s1[i])
                return dp[i][j] = solve(s1,s2,s3,i+1,j,k+1,dp); // if s2 string gets empty
            return false;
        }
        if(s3[k]==s2[j] && s3[k]==s1[i]){
            bool res1 = solve(s1,s2,s3,i+1,j,k+1,dp); //choose from string s1
            bool res2 = solve(s1,s2,s3,i,j+1,k+1,dp);  //choose from string s2;
            
            return dp[i][j] = res1||res2;
        }
        else if(s3[k]==s2[j]){
            return dp[i][j] = solve(s1,s2,s3,i,j+1,k+1,dp); // choose from string s2;
        }
        else if(s3[k]==s1[i]){
            return dp[i][j] = solve(s1,s2,s3,i+1,j,k+1,dp); // choose from string s1;
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1+s2 == s3 || s2+s1 == s3) return true;
        int n = s1.size(),m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};