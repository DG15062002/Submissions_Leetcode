class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size()/2;
        int i = 0, j = 0;
        int res = 0;
        sort(nums.begin(),nums.end());
        while(i < n && j < nums.size()){
            if(nums[j] >= nums[i]*2){
            res+=2;
            i+=1;
            }
            j+=1;
        }
        return res;
    }
};