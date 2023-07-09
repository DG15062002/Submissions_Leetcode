class Solution {
public:
bool isBeautiful(string s, int start, int end) {
    string sub = s.substr(start, end - start + 1);
    if (sub == "1" || sub == "101" || sub == "11001" || sub == "1111101" || sub == "1001110001" || sub == "110000110101" || sub == "11110100001001") {
        return true;
    }
    return false;
}
    int minimumBeautifulSubstrings(string s) {
     int n = s.length();
    vector<long long > dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (isBeautiful(s, j, i - 1)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    if(dp[n] > n || dp[n] == 0) return -1;
    return dp[n];
    }
};