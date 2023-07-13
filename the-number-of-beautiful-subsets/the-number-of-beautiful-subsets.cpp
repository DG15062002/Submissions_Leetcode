class Solution {
public:
    bool isValid(int num, int k, vector<int> &row){
        for(auto &i : row){
            if(abs(i-num) == k) return false;
        }
        return true;
    }
    void solve(int index, int k ,int &count,vector<int>& nums ,vector<int> &row)
    {
        if(index == nums.size()){
            count++;
            return;
        }
        if(isValid(nums[index],k,row)){
            row.push_back(nums[index]);
            solve(index+1,k,count,nums,row);
            row.pop_back();
        }
        solve(index+1,k,count,nums,row);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = -1;
        vector<int> row;
        solve(0,k,count,nums,row);
        return count;
    }
};