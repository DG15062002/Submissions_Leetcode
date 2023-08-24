class Solution {
public:
    int longestConsecutiveSequence(string s, int k, char ch) {
        int i = 0, j;
    for (j = 0; j < s.size(); ++j) {
        if (s[j] != ch) {
            k--;
        }
        if (k < 0) {
            if (s[i] != ch) {
                k++;
            }
            i++;
        }
    }
    return j - i;
    }
    int characterReplacement(string s, int k) {
        set<char> st;
        int ans = 0;
        for(int i =0; i < s.size(); i++)
        st.insert(s[i]);
        if(st.size() == 1) return s.size();
        for(auto ch : st){
            ans = max(ans,longestConsecutiveSequence(s,k,ch));
        }
        return ans;
    }
};