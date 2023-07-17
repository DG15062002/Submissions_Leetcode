class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
    vector<int> piles;
    
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        auto it = lower_bound(piles.begin(), piles.end(), num);
        
        if (it == piles.end()) {
            piles.push_back(num);
        } else {
            *it = num;
        }
    }
    
    return piles.size();
    }
};