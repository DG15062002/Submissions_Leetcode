class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans= "";
        int needToRemove =  k;
        for (auto i = num.begin();i!= num.end();i++) {
            while (ans != "" && needToRemove > 0 && ans.back() > *i) {
                ans.pop_back();
                needToRemove--;
            }
            ans+=(*i);
        }
        while (needToRemove--) ans.pop_back();
        if(ans == "") return "0";
        while(ans.size() > 1 && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};