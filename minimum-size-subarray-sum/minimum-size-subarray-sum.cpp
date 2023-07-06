class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total=0,reslen=1e+5,check=0;
        vector<int> sum;
        vector<int>::iterator it;
        sum.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
            sum.push_back(total);
        }
        for(int i=0;i<nums.size();i++)
        {
            it=lower_bound(sum.begin()+i+1,sum.end(),sum[i]+target);
            if(((it-sum.begin())<=nums.size())&&(*(it)>=sum[i]+target))
            {
                check=1;
                reslen=min(reslen,(int)(it-sum.begin())-i);
            }
        }
        if(check==1)
        return reslen;
        return 0;
    }
};