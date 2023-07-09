class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {-1};
        vector<int> numsdup;
        numsdup = nums;
        for(int i = 0; i < n-1; i++)
        numsdup.push_back(nums[i]);
        vector<int> res;
         stack<int> st;   // stack to store elements ahead in increasing order
        int ans[2*n-1];  // array to store next greater element
        ans[2*n-2]=-1;
        st.push(numsdup[2*n-2]);
        for(int i=2*n-3;i>=0;i--)
        {
            while((int)st.size() && st.top() <= numsdup[i])    // if the next element is lesser then remove it from stack
                st.pop();
            if((int)st.size())
            {
                ans[i]=st.top();
                st.push(numsdup[i]);
            }
            else
            {
                ans[i]=-1;
                st.push(numsdup[i]);
            }
        }
        for(int i=0;i<n;i++)
        res.push_back(ans[i]);
        return res;
    }
};