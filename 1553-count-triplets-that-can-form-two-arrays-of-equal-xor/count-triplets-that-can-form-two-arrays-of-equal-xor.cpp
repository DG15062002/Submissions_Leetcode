class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = 0, b = 0;
            for (int j = i + 1; j < n; j++) {
                a ^= arr[j - 1];
                b = 0; // Reset b to 0 before the inner loop
                for (int k = j; k < n; k++) {
                    b ^= arr[k];
                    if (a == b) ans++;
                }
            }
        }
        return ans;
    }
};