class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        while(sum != 1 && sum != 4){
            sum = 0;
            while(n > 0){
                int r = n % 10;
                sum += (r*r);
                n /= 10;
            }
            n = sum;
        }
        return sum == 1;
    }
};