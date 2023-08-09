class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(),nums.end());
        int diff1 = abs(nums[3]-nums[n-1]);
        int diff2 = abs(nums[2]-nums[n-2]);
        int diff3 = abs(nums[1]-nums[n-3]);
        int diff4 = abs(nums[0]-nums[n-4]);
        return min(min(diff1,diff2),min(diff3,diff4));
    }
};