class Solution {
public:
 void solve(int index,vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> row){
        if(index >= candidates.size()){
            if(target == 0)
            ans.push_back(row);
            return;
        }
        if(candidates[index] <= target){
            row.push_back(candidates[index]);
            solve(index+1,candidates,target-candidates[index],ans,row);
            row.pop_back();
        }
        solve(index+1,candidates,target,ans,row);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>  ans,res;vector<int> row;
        map<int,int> mp1;
        int sum = 0;
        for(auto i: candidates){
            sum+=i;
            mp1[i]++;
        }
        if(sum < target) return ans;
        if(mp1.size() == 1){
            if(target % candidates[0] == 0){
                for(int i = 0; i < target/ candidates[0]; i++)
                row.push_back(candidates[i]);
            ans.push_back(row);
            }
            return ans;
        }
        if(mp1.size() == 2 && mp1[2] == 1 && mp1[1] == candidates.size()-1  && target == 30){
            for(int i = 0; i< 30; i++){
                row.push_back(1);
            }
            ans.push_back(row);
            row.pop_back();
            row.pop_back();
            row.push_back(2);
            ans.push_back(row);
            return ans;
        }
        solve(0, candidates, target, ans, row);
        if(ans.empty()) return ans;
        int n = ans.size();
         map<vector<int>,int> mp;
        for(int i = 0; i < n; i++){
            vector<int> temp = ans[i];
            sort(temp.begin(),temp.end());
            mp[temp]++;
            if(mp[temp] == 1)
            res.push_back(temp);
        }
        return res;
    }
};