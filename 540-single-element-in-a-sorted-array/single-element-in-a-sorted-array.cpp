class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
	    if(n == 1) return nums[0];
	    for(int i = 0 ; i < n ; i+=2){
				if(i -1 > 0 && i+1 < n){
	        if(nums[i-1] != nums[i] && nums[i+1] != nums[i])
					return nums[i];
				}
				else	if(i - 1 > 0){
					if(nums[i-1] != nums[i])
					return nums[i];
				}
				else if(i + 1 < n){
					if(nums[i+1] != nums[i])
					return nums[i];
				}
	    }
	    return 0;
    }
};