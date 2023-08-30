class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        if(n == 1) return ans;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        if(temp == nums) return ans;
        int prev = nums[n-1];
        for(int i=n-2;i>=0;i--){
		int noOfTime=nums[i]/prev;   
		if((nums[i])%prev!=0){
			noOfTime++;
			prev=nums[i]/noOfTime;
		}   
		ans+=noOfTime-1;
	}
        return ans;
    }
};