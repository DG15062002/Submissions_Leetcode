class Solution {
public:
    bool isPalindrome(string s){
        string k = s;
        reverse(k.begin(), k.end());
        return k == s;
    }
    bool isStrictlyPalindromic(int n) {
        bool ans = true;
        if(n == 4) return false;
        for(int i =2; i <= n-2; i++){
            int temp = n; string str = "";
            while(temp > 0){
                int r = temp % i;
                str+= to_string(r);
                temp /= i;
            }
            while(str.back() == '0'){
                str.pop_back();
            }
            if(!isPalindrome(str)) return false;
        }
        return true;
    }
};