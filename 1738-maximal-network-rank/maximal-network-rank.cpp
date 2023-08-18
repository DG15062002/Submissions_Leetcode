class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,int> mp;
        map<int,set<int>> adj;
        int ans = 0;
        for(int i = 0; i < roads.size(); i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        for(int i = 0; i <= n-2; i++){
            for(int j = i+1; j <= n-1; j++){
                if(adj[i].find(j) == adj[i].end()){
                    ans = max(ans, mp[i]+mp[j]);
                }
                else
                    ans = max(ans, mp[i]+mp[j]-1);
            }
        }
        return ans;
    }
};