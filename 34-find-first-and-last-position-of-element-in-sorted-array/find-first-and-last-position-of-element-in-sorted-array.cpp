class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        vector<int>::iterator upper,lower;
        lower=lower_bound(nums.begin(),nums.end(),target);
        upper=upper_bound(nums.begin(),nums.end(),target);
        if(upper==lower)
        { res.push_back(-1);
        res.push_back(-1);
        }
        else
        {
            res.push_back((int)(lower-nums.begin()));
            if(int(upper-lower)==1)
                res.push_back((int)(lower-nums.begin()));
            else
                res.push_back((int)(upper-nums.begin())-1);
        }
            return res;
    }
};