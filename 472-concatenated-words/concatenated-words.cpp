class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordDict(words.begin(), words.end());
        vector<string> ans;

        for (string word : words) {
            wordDict.erase(word);
            if (!word.empty() && wordBreak(word, wordDict)) {
                ans.push_back(word);
            }
            wordDict.insert(word);
        }

        return ans;
    }
};
