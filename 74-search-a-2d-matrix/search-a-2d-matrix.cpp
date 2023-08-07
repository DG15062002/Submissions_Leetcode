class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         vector<int> res;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                res.push_back(matrix[i][j]);
            }
        }
        sort(res.begin(),res.end());
        auto lower=lower_bound(res.begin(),res.end(),target);
        auto upper=upper_bound(res.begin(),res.end(),target);
        if(lower!=upper)
            return true;
        return false;
    }
};