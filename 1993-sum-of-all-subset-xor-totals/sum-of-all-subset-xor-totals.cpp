class Solution {
public:
    void subsetsum(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        subsetsum(index + 1, nums, subset, result);
        subset.pop_back();
        subsetsum(index + 1, nums, subset, result);
    }
    int subsetXORSum(vector<int>& nums) {
         vector<int> subset;
        vector<vector<int>> result;
        subsetsum(0, nums, subset, result);
        int ans = 0;
        for(int i = 0; i < result.size(); i++){
            if(result[i].empty()) continue;
            int temp = 0;
            for(int j = 0; j < result[i].size();j++)
            temp ^= result[i][j];
            ans+=temp;
        }
        return ans;
    }
};