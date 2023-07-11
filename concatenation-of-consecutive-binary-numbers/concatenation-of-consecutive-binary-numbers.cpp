class Solution {
public:
    int concatenatedBinary(int n) {
        long long val = 0;
        int i = 1;
        int mod = 1e9+7;
        while(i <= n){
            int digits = 1+log2(i);
            val = ((val<<digits)%mod+i)%mod;
            i+=1;
        }
        return val;
    }
};