class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
    int n = nums.size();
       if(n == 1) return 1;
    long long  maxFreq = 0;
    long long  left = 0;
    long long  operations = 0;

    for (long long  right = 1; right < n; right++) {
        operations += (nums[right] - nums[right - 1]) * (right - left);
        while (operations > k) {
            operations -= nums[right] - nums[left];
            left++;
        }
        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
    }
};