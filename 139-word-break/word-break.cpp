class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
          vector<int> dp(s.size()+1,0);
        dp[s.size()]=1;
        for(int i=s.size()-1; i>=0; i--){
            for(auto w:wordDict){
                if(i+w.size()<=s.size() and s.substr(i, w.size())==w){
                    dp[i]=dp[i+w.size()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};