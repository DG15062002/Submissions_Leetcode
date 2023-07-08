class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
       int n=weights.size();
       if(n == 1 || k == 1) return 0; 
        vector<long long> div(n, 2e9+1);
        for(int i=1; i<n; i++){
            div[i]=weights[i]+weights[i-1];
        }
        sort(div.begin(), div.end());
        long long maxm= weights[0]+weights[n-1];
        long long minm=weights[0]+weights[n-1];
        for(int i=0; i<k-1; i++){
            minm+=div[i];
        }
        for(int i=n-2; i>n-k-1; i--){
            maxm+=div[i];
        }
        return (maxm-minm);
    }
};
