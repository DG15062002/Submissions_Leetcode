class Solution {
public:
    void solve(vector<vector<int>> &graph,int index,vector<vector<int>> &ans, vector<int> row){
        row.push_back(index);
        if(index == graph.size()-1){
            ans.push_back(row);
        }
        else{
            for(auto i : graph[index])
            solve(graph,i,ans,row);
        }
      row.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> row;
        solve(graph,0,ans,row);
        return ans;
    }
};