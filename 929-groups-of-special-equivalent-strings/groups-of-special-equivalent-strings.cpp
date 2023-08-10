class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        map<pair<multiset<char>,multiset<char>>,int> mp;
        int ans = 0;
        for(string word : words){
            multiset<char>even,odd;
            for(int i = 0; i < word.size(); i++){
                if(i%2 == 0)
                even.insert(word[i]);
                else
                odd.insert(word[i]);
            }
            mp[{even,odd}]++;
        }
        return mp.size();
    }
};