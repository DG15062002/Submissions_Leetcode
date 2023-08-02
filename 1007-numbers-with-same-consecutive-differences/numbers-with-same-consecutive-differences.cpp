class Solution {
public:
    void solve(int i, int n, int k, vector<char>& digits, string& row, vector<int>& ans) {
        if (row.size() == n) {
            if(row[0] != '0')
            ans.push_back(stoi(row));
            return;
        }

        for (int j = 0; j < digits.size(); j++) {
            if (i == -1 || abs(row[i] - digits[j]) == k) {
                row.push_back(digits[j]);
                solve(i + 1, n, k, digits, row, ans);
                row.pop_back();
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        vector<char> digits = {'0','1','2','3','4','5','6','7','8','9'};
        string row = "";

        for (int i = 0; i < digits.size(); i++) {
            if (n > 1 || digits[i] != '0') { // Skip numbers with leading zero if n > 1
                row.push_back(digits[i]);
                solve(0, n, k, digits, row, ans);
                row.pop_back();
            }
        }

        return ans;
    }
};
