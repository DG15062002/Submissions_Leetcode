class Solution {
public:
    vector<vector<int>> ans;
    vector<int> row;
    void solve(int n, int k, int i){
        if(row.size() == k){
            ans.push_back(row);
            return;
        }
        for(int j = i; j <= n; j++){
            row.push_back(j);
            solve(n,k,j+1);
            row.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);
        return ans;
    }
};