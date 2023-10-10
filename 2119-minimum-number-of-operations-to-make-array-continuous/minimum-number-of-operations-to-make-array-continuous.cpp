class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
        
        std::sort(nums.begin(), nums.end());  // Sort `nums` in ascending order.
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());  // Remove duplicates.

        int ans = n;
        for (int i = 0; i < nums.size(); ++i) {
            int start = nums[i];
            int end = start + n - 1;
            auto it = std::upper_bound(nums.begin(), nums.end(), end);  // Find right insert position
            int uniqueLen = std::distance(nums.begin() + i, it);
            ans = std::min(ans, n - uniqueLen);
        }
        
        return ans;
    }
};