class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        // Scenario 1: Rob the first house and exclude the last house
        int max1 = robHelper(nums, 0, nums.size() - 2);
        
        // Scenario 2: Rob the last house and exclude the first house
        int max2 = robHelper(nums, 1, nums.size() - 1);
        
        // Return the maximum amount between the two scenarios
        return max(max1, max2);
    }
    
    int robHelper(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        
        for (int i = start; i <= end; i++) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = temp;
        }
        
        return prev1;
    }
};
