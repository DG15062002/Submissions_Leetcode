class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<pair<int,int>,int> mp;
        for(auto i : coordinates){
            int x = i[0];
            int y = i[1];
            if(x == m-1 && y == n-1) // if last cell
            mp[{x-1,y-1}]++;
            else
            if(y == n-1){ // if last column
            mp[{x,y-1}]++;
            mp[{x-1,y-1}]++;
            }
            else
            if(x == m-1){ // if last row
                mp[{x-1,y}]++;
            mp[{x-1,y-1}]++;
            }
            else{ // normal cells
            mp[{x-1,y}]++;
            mp[{x,y-1}]++;
            mp[{x-1,y-1}]++;
            mp[{x,y}]++;
            }
        }
        vector<long long> ans(5,0);
        for(auto[a,b] : mp){
            if(a.first >= 0 && a.second >= 0) // don't count invalid cells
            ans[b]++;
        }
        int sum = accumulate(ans.begin(),ans.end(),0); // total count of 1,2,3 and 4 number of cells
        ans[0] =(long long)(m-1)*(long long)(n-1)-sum;
        return ans;
    }
};