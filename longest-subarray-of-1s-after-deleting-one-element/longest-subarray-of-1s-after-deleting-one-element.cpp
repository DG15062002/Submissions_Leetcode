class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(),ans = 0 ;
        if(n == 1) {if(nums[0] == 0) return 0; return 1;}
        vector<int> leftOnes,rightOnes,zeroIndex;
        int l = 0,r = 0,check1 = 0, check2 = 0;
        leftOnes.push_back(0);
        rightOnes.push_back(0);
        for(int i = 0 ; i < n; i++){
            if(nums[i] == 1){
                if(check1 == 0)
                check1 = 1;
                l++;
            }
            else{
                check1 = 0;
                zeroIndex.push_back(i);
                l = 0;
            }
            leftOnes.push_back(l);
        }
         for(int i = n-1 ; i >= 0; i--){
            if(nums[i] == 1){
                if(check2 == 0)
                check2 = 1;
                r++;
            }
            else{
                check2 = 0;
                r = 0;
            }
            rightOnes.push_back(r);
        }
        reverse(rightOnes.begin(),rightOnes.end());
        if(zeroIndex.size() == 0)
        return n-1;
        for(int i = 0; i< zeroIndex.size(); i++)
        ans = max(ans,leftOnes[zeroIndex[i]]+rightOnes[zeroIndex[i]+1]);
        return ans;
    }
};