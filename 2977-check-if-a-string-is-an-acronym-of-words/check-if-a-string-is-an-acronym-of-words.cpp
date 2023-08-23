class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string acr = "";
        for(string word : words){
            acr += word[0];
        }
        return acr == s;
    }
};