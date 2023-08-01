class Solution {
public:
    bool isValid(string& ans, string& s) {
        string temp = ans;
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        return temp == s;
    }

    void solve(int i, string& s,/*unordered_set*/vector<string>& wordDict, string& ans, vector<string>& res) {
        if (i >= s.size()) {
            if (isValid(ans, s)) {
                if (ans.back() == ' ')
                    ans.pop_back();
                res.push_back(ans);
            }
            return;
        }

        for (string word : wordDict) {
            int n = word.size();
            if (i + n <= s.size() && s.substr(i, n) == word) {
                string temp = ans;
                if (!temp.empty())
                    temp += " ";
                temp += word;
                solve(i + n, s, wordDict, temp, res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<std::string> res;
        string ans;
        // unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        solve(0, s, /*wordSet*/wordDict, ans, res);
        return res;
    }
};