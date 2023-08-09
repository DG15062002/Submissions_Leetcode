class Solution {
public:
    bool valid(vector<int>& nums, int p, int mid) {
        int count = 0;
      for (int i = 0; i < nums.size() - 1 && count < p;) {
            if (nums[i+1] - nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        
        return count >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) / 2;
            if (valid(nums, p, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
