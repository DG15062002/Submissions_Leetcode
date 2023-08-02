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
    int countMaxOrSubsets(vector<int>& nums) {
          vector<int> subset;
        vector<vector<int>> result;
        subsetsum(0, nums, subset, result);
        map<int,int> mp;
        int maxAns = 0;
        for(int i = 0; i < result.size(); i++){
            int temp = 0;
            if(result[i].empty()) continue;
            for(int j = 0; j < result[i].size(); j++){
                temp |= result[i][j];
            }
            mp[temp]++;
        }
        return mp.rbegin()->second;
    }
};