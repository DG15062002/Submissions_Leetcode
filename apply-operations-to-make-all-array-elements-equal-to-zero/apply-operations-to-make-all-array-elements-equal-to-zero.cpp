class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
 int n = nums.size();
        if(n == 1) return true;
        if(n == 2){
            if(k == 1) return true;
            if(nums[0] == nums[1]) return true;
            return false;
        }
        if(k == 1) return true;
        vector<long long> pref(n+1,0);
        long long ac = 0;
        for(int i = 0;i<n;i++){
            ac-=pref[i];
            nums[i]-=ac;
            
            if(nums[i]<0) return false;
            if(i+k<=n){   
                ac+=nums[i];
                pref[i+k]+=nums[i];
                nums[i] = 0;
            }
            else if(nums[i]>0)return false;
        }
        return true;
    }
};