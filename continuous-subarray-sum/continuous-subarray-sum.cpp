class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1)
			return false;
		if(k==1)
			return true; 
        unordered_map<int,int> mp;
        int sum = nums[0]%k;
          mp[sum] = 0;
        for(int i = 1 ; i < nums.size(); i++){
            sum= (sum + nums[i])%k;
              if((mp.find(sum) != mp.end() && mp[sum] != i-1) || (sum == 0))
          return true;
          if(mp.find(sum) == mp.end())
          mp[sum] = i;
        }
        return false;
    }
};