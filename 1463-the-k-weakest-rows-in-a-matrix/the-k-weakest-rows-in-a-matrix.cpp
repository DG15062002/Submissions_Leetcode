class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;vector<pair<int,int>> res;vector<pair<int,int>>::iterator it,it1;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                    count++;
            }
            res.push_back({count,i});
        }
        sort(res.begin(),res.end());
        it1=res.begin();advance(it1,k);
        for(it=res.begin();it!=it1;it++)
            ans.push_back(it->second);
        return ans;
    }
};