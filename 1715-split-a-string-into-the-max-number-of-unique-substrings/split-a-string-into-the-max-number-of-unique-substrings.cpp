class Solution {
public:
    void solve(int i,string s,set<string> &st, int &ans){
          if (i >= s.size()) {
            ans = max(ans, (int)st.size());
            return;
        }
        
        for (int j = i + 1; j <= s.size(); j++) {
            string temp = s.substr(i, j - i);
            if (st.find(temp) != st.end()) {
                continue;
            }
            
            st.insert(temp);
            solve(j, s, st, ans);
            st.erase(temp);
        }
    } 
    int maxUniqueSplit(string s) {
        if(s.size() == 1) return 1;
        set<string> st;
        int ans = 1;
        solve(0,s,st,ans);
        return ans;
    }
};