class Solution {
public:    
    vector<long long> getDistances(vector<int>& arr) {
         int n = arr.size();
        vector<long long> ans(n);
        unordered_map<long long,long long> sum,freq,currfreq,currsum;

        for(int i = 0;i<n;i++)
        {
           sum[arr[i]]+=i;
           freq[arr[i]]++;
        }

        for(int i = 0;i<n;i++)
        {
           currfreq[arr[i]]++;
           currsum[arr[i]]+=i;

           long long currfrq = currfreq[arr[i]]-1,remfreq = freq[arr[i]]-currfreq[arr[i]];
           long long currsumval = currsum[arr[i]],remsum = sum[arr[i]]-currsum[arr[i]];
           ans[i] =  abs(i*currfrq-(currsumval-i))+abs(i*remfreq-remsum);
        }
        return ans;
    }
};