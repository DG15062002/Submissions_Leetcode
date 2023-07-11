class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> state(n);
        for(int i = 0; i < n; i++){
            for(char ch : words[i]){
                state[i] |= 1<<(ch-'a');
            }
            for(int j = 0; j < i; j++){
                if(!(state[i] & state[j])){
                    int currans = words[i].size()*words[j].size();
                    ans = max(ans,currans);
                }

            }
        }
        return ans;
    }
};