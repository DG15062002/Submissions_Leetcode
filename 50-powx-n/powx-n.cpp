class Solution {
public:
    double solve(double x, long long n){
        double ans = 1;
        while(n > 0){
            int c = n & 1;
            if(c == 1){
                ans = ans*x;
            }
            x = x*x;
            n = n >> 1;
        }
        return ans;
    }
    double myPow(double x, int n) {
    if(x == 1) return 1;
    double ans = solve(x,abs(n));
    if(n < 0)
    return 1/ans;
    cout << INT_MAX;
    return ans;
    }
};