class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans = "";
        int n = s1.size();
        map<char,char> mp;
        for(char ch = 'a'; ch <= 'z'; ch++)
        mp[ch] = ch;
        map<char,vector<char>> mp2;
        for(int i = 0; i < n; i++){
            mp[s1[i]] = min(mp[s1[i]],min(s1[i],s2[i]));
            mp[s2[i]] = min(mp[s2[i]],min(s1[i],s2[i]));
            mp2[s1[i]].push_back(s2[i]);
            mp2[s2[i]].push_back(s1[i]);
        }
        for(auto i = mp2.begin(); i != mp2.end(); i++){
           for(char ch : i->second){
               mp[i->first] = min(mp[i->first],mp[ch]);
               mp[ch] = min(mp[i->first],mp[ch]);
           } 
        }
         for(auto i = mp2.begin(); i != mp2.end(); i++){
           for(char ch : i->second){
               mp[i->first] = min(mp[i->first],mp[ch]);
               mp[ch] = min(mp[i->first],mp[ch]);
           } 
        }
        for(int i = 0; i < baseStr.size(); i++){
            if(mp.find(baseStr[i]) == mp.end()){
                ans += baseStr[i];
            }
           else ans+= mp[baseStr[i]];
        }
        return ans;
    }
};