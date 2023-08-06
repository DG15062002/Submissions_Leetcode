class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        if(nums.size() == 1) return 1;
        vector<int> prefSum;
        map<vector<int>,int> mp;
        int count = 0;
        prefSum.push_back(0);
        for(auto i : nums){
            if(i % p == 0)
            count++;
            prefSum.push_back(count);
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size()+1; j++){
                if(prefSum[j]-prefSum[i] <= k)
                mp[vector(nums.begin()+i,nums.begin()+j)]++;
            }
        }
        return mp.size();
    }
};